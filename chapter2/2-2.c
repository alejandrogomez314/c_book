#include <stdio.h>
#define MAXLINE 256

int main(void) {
  int i, c;
  char s[MAXLINE];
  for (i = 0; i < MAXLINE - 1; i++) {
    if ((c = getchar()) == '\n')
      break;
    if (c == EOF)
      break;
    s[i] = c;
  }
  s[i] = '\0';
  printf("%s\n", s);
  return 0;
}
