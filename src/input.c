#include "utilities.h"

char readKey(){
    char c ;
    int err;
    while( (err = read(STDIN_FILENO,&c,sizeof(char)) != 1 )){
        if (err == -1 && errno != EAGAIN)
            die("read");
    }
    return c;
}
