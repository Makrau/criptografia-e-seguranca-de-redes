#include <stdio.h>
#include <stdlib.h>

char* read_from_file (const char* filename)
{
  char ch, *s;
  FILE *fd;
  int c = 0;

  s = (char *)(malloc)(sizeof(char));
  fd = fopen(filename, "r");

  while((ch=fgetc(fd)) != EOF){
    s[c] = ch;
    c++;
    s = (char *) realloc(s, (c+1) * sizeof(char));
  }
  s[c] = '\0';

  fclose(fd);
  return s;
}
