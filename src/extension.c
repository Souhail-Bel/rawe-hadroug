#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void runProgram(char *cmd) {
  write(STDOUT_FILENO, "\033[2J", 4);
  write(STDOUT_FILENO, "\033[H", 3);

  disableRawMode();

  // safe :)
  system(cmd);

  printf("\n\nPress any key to continue...");
  getchar();

  enableRawMode();
}

void runJava() {
  if (e.filename == NULL)
    return;

  char cmd[512];
  char class_name[256];

  snprintf(class_name, sizeof(class_name), "%s", e.filename);

  char *ext = strrchr(class_name, '.');
  if (ext != NULL)
    *ext = '\0';

  snprintf(cmd, sizeof(cmd), "javac %s && java %s", e.filename, class_name);

  runProgram(cmd);
}
