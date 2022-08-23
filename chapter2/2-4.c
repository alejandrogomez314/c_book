#include <stdio.h>
#include <string.h>
void squeeze(char s1[], char s2[]);

char s1[] = {
  'a','b','c','d','e','\0'
};

char s2[] = {
  'b','d','z','j', '\0'
};

int main(void) {
  printf("array 1: %s\n", s1);
  printf("array 2: %s\n", s2);
  squeeze(s1, s2);
  printf("squeezed array: %s", s1);
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;
  int match;
  for (i = j = 0; s1[i] != '\0'; i++) {
    match = 0;
    for (k = 0; s2[k] != '\0' && !match; k++) {
      if (s1[i] == s2[k]) {
       match = 1; 
      }
    }
    if (!match) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}
