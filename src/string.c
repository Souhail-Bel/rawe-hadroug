#include "utilities.h"

void initString(struct string *ab){
    ab->b = (char*)malloc(sizeof(char));
    ab->len = 0;
}
void stringAppend(struct string *ab , const char* c , int len){
    char* new = realloc(ab->b, ab->len + len + 1);
    if(new == NULL) return ;
    strncpy(ab->b+ab->len , c, len);
    ab->b = new;
    ab->len +=len;
    ab->b[ab->len] = '\0';
}
void stringFree(struct string* ab){
    free(ab->b);
}
