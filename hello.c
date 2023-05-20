#include <stdio.h>

int my_strlen(char *s) {
  int count = 0;

  while (s[count] != '\0')
    count++;

  return count;
}

int main(void) {
  FILE *fp;

  char s[1024];
  int linecount = 0;

  fp = fopen("quote.txt", "r");

  while (fgets(s, sizeof s, fp) != NULL)
    printf("%d: %s", ++linecount, s);

  fclose(fp);
}
