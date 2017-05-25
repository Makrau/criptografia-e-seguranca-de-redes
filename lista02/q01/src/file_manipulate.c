#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_from_file(const char* filename){
  char ch, *s;
  FILE *fd;
  int c = 0;

  s = (char *)(malloc)(sizeof(char));
  fd = fopen(filename, "r");

  while((ch=fgetc(fd)) != EOF){
    if(ch == '\n')
      s[c] = ' ';
    else
      s[c] = ch;
    c++;
    s = (char *) realloc(s, (c+1) * sizeof(char));
  }
  s[c] = '\0';

  fclose(fd);
  return s;
}

char *append_plaintext(char* plaintext){
  int plaintext_size, mod, i;
  plaintext_size = strlen(plaintext);
  mod = 16 - (plaintext_size % 16);
  /* printf("%d\n", plaintext_size); */
  /* printf("%d\n", mod); */
  if(mod == 16){
    return plaintext;
  }
  else{
    plaintext = (char *) realloc(plaintext, (plaintext_size+mod) * sizeof(char));
    if(plaintext == NULL){
      printf("Sem espaço suficiente\n");
    }
    for(i = plaintext_size; i < plaintext_size + mod; ++i){
      plaintext[i] = '*';
    }
    plaintext_size = strlen(plaintext);
    /* printf("%d\n", plaintext_size); */
    return plaintext;
  }
}
