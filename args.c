#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  int total = 0;

  for (int i = 1; i < argc; i++) {
    int value = atoi(argv[i]);

    total += value;
  }

  printf("%d\n", total);
}
