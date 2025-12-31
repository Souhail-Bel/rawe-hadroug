#include "utilities.h"

#define CTRL_KEY(k) ((k)-'a'+1)
void refreshScreen(){
    struct string ab = initString();

    stringAppend(&ab,"\x1b[2J",4);
    stringAppend(&ab, "\x1b[H" ,3);
    
    drawRows(&ab);
    char ch[100];
    snprintf(ch,sizeof(ch), "\x1b[%d;%dH",e.cy+1 ,e.cx+1);
    stringAppend(&ab, ch ,strlen(ch));

    write(STDOUT_FILENO ,ab.b,ab.len);
    stringFree(&ab);
}

void drawRows(struct string *ab){
    for (int y =0;y<e.windowsLength;y++){
        if (y == 0) {
            char welcome[80];
            
            int welcomelen = snprintf(welcome, sizeof(welcome),
                    "Welcome to my text editor !");
            if (welcomelen > e.windowsLength) welcomelen = e.windowsLength;
            
            stringAppend(ab, welcome, welcomelen);
        } 
        else {
          stringAppend(ab, "~", 1);
        }

        if (y<e.windowsLength -1)
            stringAppend(ab ,"\r\n" ,2);
    }
}
