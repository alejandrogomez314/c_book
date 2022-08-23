#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
void itoa(int n, char[]);

int main(void) {
  char s[MAX];
  for (int i = 0; i < MAX; i++)
    s[i] = 0;
  itoa(41, s);
  printf("%s\n", s);  
  return 0;
}

void itoa(int n, char s[]) {
 static int i;

 if (n / 10)
   itoa(n / 10, s);
 else {
   i = 0;
   if (n < 0)
     s[i++] = '-';
  }
  printf("%d\n", n%10);
  s[i++] = abs(n)%10 + '0';
  s[i] = '\0';
}

