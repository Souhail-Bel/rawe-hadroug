#include "utilities.h"


void insertChar(char c){
    struct string* current_row = e.rowBuff+e.cy+e.rowoff;
    int current_col = e.cx;
     
    if(current_col < current_row ->len){
        current_row->b = realloc(current_row->b , current_row->len + 2);
        memcpy(current_row->b+current_col+1 ,current_row->b+current_col ,current_row->len-current_col);
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
}
