#include "utilities.h"

struct string initString(){
    struct string ab ;
    ab.b = (char*)malloc(sizeof(char));
    ab.len = 0;
    return ab;
}
void stringAppend(struct string *ab , const char* c , int len){
    char* new = realloc(ab->b, ab->len + len);
    if(new == NULL) return ;
    strncpy(ab->b+ab->len , c, len);
    ab->b = new;
    ab->len +=len;
}
void stringFree(struct string* ab){
    free(ab->b);
}
