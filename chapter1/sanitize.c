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
#include <ctype.h>

int main(){
  char c;

  while ((c = getchar()) != EOF) {
    switch(c) {
      case ' ':
      case '\t':
        while ((c = getchar()) == ' ');
        if (c != '\n')
          putchar(' ');
        if (c == EOF)
          break;
      case '\n':
        while ((c = getchar()) == '\n');
        putchar('\n');
        if (c == EOF)
          break;
        putchar(c);
      default:
        putchar(c);
    }
  }

  return 0;
}

