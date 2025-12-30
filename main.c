#include <asm-generic/errno-base.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

/////* Global Data*////
struct termios original_term;

///*Terminal*///

void die(const char* s){
    perror(s);
    exit(1);
}

void disableRawMode(){
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH,&original_term) == -1) die("tcsetattr");
}

void enableRawMode(){
    if (tcgetattr(STDIN_FILENO, &original_term) == -1) die("tcgetattr");
    atexit(disableRawMode);


    struct termios raw = original_term;
    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN );
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |=(CS8);
    raw.c_cc[VMIN]=0;
    raw.c_cc[VTIME]=1;
    if (tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw) == -1) die("tcsetattr");
}


int main (){
    enableRawMode();

    char c ;
    while (1){
        c = '\0';
        if (read(STDIN_FILENO,&c,sizeof(char)) == -1 && errno != EAGAIN) die("read");

        if(iscntrl(c)){
            printf("%d\r\n",c);
        }
        else {
            printf("%d(%c)\r\n",c,c);
        }
        if (c=='q')
            exit(0);
    }
    return 0;
}
