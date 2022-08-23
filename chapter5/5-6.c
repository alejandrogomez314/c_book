#include <stdio.h>

#define MAXLINE 1000

int _getline(char *s, int lim)
{
  int c;
  char *bs = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';
  return s-bs;
}

int main(void)
{
  char s[100];
  int lim = MAXLINE - 1;
  int length = _getline(s, lim);
  printf("length: %d\nstring: %s\n", length, s);
  return 0;
}
