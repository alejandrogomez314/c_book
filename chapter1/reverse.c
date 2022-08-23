/*
 * =====================================================================================
 *
 *       Filename:  longest-line.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 23:15:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void reverse(char str[], int len);

int main(){
  int len;
  char line[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0)
      reverse(line, len);

  return 0;
}

int _getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

void reverse(char str[], int len) {
  int i, j;

  i = 0, j = len-2; // length - 1 - \n - \0
  while (i < j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    i++;
    j--;
  }
  for (i = 0; i < len; i++)
    printf("%c", str[i]);
}

