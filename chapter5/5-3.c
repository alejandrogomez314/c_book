#include <stdio.h>

void _strcat(char *s, char *t);

int main(void) 
{
  char s[12] = "hello";
  char *t = "world";
  _strcat(s, t);
  printf("%s\n", t);
  return 0;
}

void _strcat(char *s, char *t)
{
  while (*s++);
  while (*s++ = *t++);
}
