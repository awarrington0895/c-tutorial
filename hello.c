#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s) {
  int count = 0;

  while (s[count] != '\0')
    count++;

  return count;
}

void readQuote(void) {
  FILE *fp;

  char s[1024];
  int linecount = 0;

  fp = fopen("quote.txt", "r");

  while (fgets(s, sizeof s, fp) != NULL)
    printf("%d: %s", ++linecount, s);

  fclose(fp);
}

void whales(void) {
  FILE *fp;

  char name[1024];
  float length;
  int mass;

  fp = fopen("whales.txt", "r");

  while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

  fclose(fp);
}

void write_files(void) {
  FILE *fp;

  int x = 32;

  fp = fopen("output.txt", "w");

  fputc('B', fp);

  fputc('\n', fp);

  fprintf(fp, "x = %d\n", x);
  fputs("Hello, world!\n", fp);

  fclose(fp);
}

void write_bytes(void) {
  FILE *fp;
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};

  fp = fopen("output.bin", "wb");

  fwrite(bytes, sizeof(char), 6, fp);

  fclose(fp);
}


void read_bytes(void) {
  FILE *fp;

  unsigned char c;

  fp = fopen("output.bin", "rb");

  while (fread(&c, sizeof(char), 1, fp) > 0)
    printf("%d\n", c);
}

char* readline(FILE* fp) {
  int offset = 0; // Index next char goes in the buffer
  int bufsize = 4; //Preferably power of 2 initial size
  char* buf; // The buffer
  int c; // The character we have read in

  buf = malloc(bufsize);

  if (buf == NULL) 
    return NULL;

  while (c = fgetc(fp), c != '\n' && c != EOF) {
    // Check if we're out of room in the buffer accounting
    // for the extra byte for the NUL terminator
    if (offset == bufsize - 1) { // -1 for the NUL terminator
      bufsize *= 2;

      char* newBuf = realloc(buf, bufsize);

      if (newBuf == NULL) {
        free(buf);
        return NULL;
      }

      buf = newBuf;
    }

    buf[offset++] = c;
  }

  if (c == EOF && offset == 0) {
    free(buf);
    return NULL;
  }

  // Shrink to fit
  if (offset < bufsize - 1) {
    char* newBuf = realloc(buf, offset + 1);

    if (newBuf != NULL)
      buf = newBuf;
  }

  buf[offset] = '\0';

  return buf;
}


int main(void) {
  FILE* fp = fopen("quote.txt", "r");

  char* line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  fclose(fp);
}








