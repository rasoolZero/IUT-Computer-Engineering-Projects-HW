#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(char *input) {
  char buffer[128];
  strcpy(buffer, input);
  printf("buffer is: %s\n", buffer);
  return;
}

int main(int argc, char *argv[]) {

  if (argc == 1)
    return 1;
  copy(argv[1]);

  return 0;
}
