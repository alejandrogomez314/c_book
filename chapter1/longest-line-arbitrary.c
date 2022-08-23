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
void copy(char to[], char from[]);

int main(){
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = _getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)
    printf("%s", longest);

  return 0;
}

int _getline(char s[], int lim) {
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    if (i < lim)
      s[i] = c;
  if (c == '\n') {
    if (i < lim) {
      s[i] = c;
      s[i+1] = '\0';
    }
    i++;
  }
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}

