#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAXLINE 256

int htoi(const char input[]);
int _getline(char s[], int lim);
int main(void) {
  int len;
  char line[MAXLINE];
  
  while ((len = _getline(line, MAXLINE)) > 0) {
    printf("input: %s, output: %d\n", line, htoi(line));
  }
  return 0;
}

int _getline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}

int htoi(const char hexstr[]) {
  int result = 0;
  int i = 0, c, pos;

  // allow optional 0x or 0X
  if (hexstr[0] == '0' && (hexstr[1] == 'x' || hexstr[1] == 'X'))
    i += 2;

  // calculate num of positions
  pos = strlen(hexstr)-1-i;

  // check char is within desired input range. Note: letters must be all upper
  // or lower case, not mixed.
  while (i < strlen(hexstr) && ((hexstr[i] >= '0' && hexstr[i] <= '9') ||
                                (hexstr[i] >= 'a' && hexstr[i] <= 'f') ||
                                (hexstr[i] >= 'A' && hexstr[i] <= 'F'))) {
    c = hexstr[i];
    if (isalpha(c)) {
      c = tolower(c); 
      if (c == 'a')
        c = 10;
      else if (c == 'b')
        c = 11;
      else if (c == 'c')
        c = 12;
      else if (c == 'd')
        c = 13;
      else if (c == 'e')
        c = 14;
      else if (c == 'f')
        c = 15;
    } else {
      c = c - '0';
    }
    result += pow(16,pos) * c;
    i++;
    pos--;
  }
  return result;
}
