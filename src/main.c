#include "utilities.h"

/////* Global Data*////

extern struct editorConfig e;



int main (){
    enableRawMode();
    initEditorConfig();
    while (1){
        handleKeys();
        refreshScreen();
    }
    return 0;
}
