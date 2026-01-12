#include "utilities.h"


void insertChar(char c){
    struct string* current_row = e.rowBuff+e.cy+e.rowoff;
    int current_col = e.cx;
     
    if(current_col < current_row ->len){
        current_row->b = realloc(current_row->b , current_row->len + 2);
        memmove(current_row->b+current_col+1 ,current_row->b+current_col ,current_row->len-current_col);
        current_row->b[current_col]=c;
        current_row->len++;
        current_row->b[current_row->len]='\0';
    }
    if (current_col >= current_row->len || !current_row){
        char buf[1000];
        int i = 0;
        while (i <  current_col-current_row->len) memcpy(buf+i++, " " ,1);
        memcpy(buf+i,&c,1);
        stringAppend(current_row,buf,strlen(buf));
    }
    e.modification_num++;
}

int removeChar(){
    struct string* current_row = e.rowBuff+e.cy+e.rowoff;
    if (e.cy+e.rowoff < e.rowsNum && e.cx+e.coloff != 0){
        memmove(current_row->b+e.cx+e.coloff-1 ,current_row->b+e.coloff+e.cx ,current_row->len - e.cx);
        current_row->len --;
        current_row->b[current_row->len]='\0';
        e.modification_num++;
        return 1;
    }
    return 0;
}


void saveToDisk (){
    FILE* file = fopen(e.filePath,"w");
    if (file == NULL) die("fopen") ;
    
    for (int i =0 ;i<e.rowsNum ;i++){
        if(e.rowBuff[i].len) write(fileno(file), e.rowBuff[i].b,e.rowBuff[i].len);

        if (i != e.rowsNum-1){
            write(fileno(file),"\n",1);
        }
    }
    e.modification_num = 0;
    fclose(file);
}
