#ifndef UTILIS
#define UTILIS
#include <termios.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

/// Terminal ///
void handleKeys();
void enableRawMode();
void disableRawMode();
void die(const char* s);

/// Input ///
char readKey();

#endif
