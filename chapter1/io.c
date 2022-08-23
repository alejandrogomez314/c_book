/*
 * =====================================================================================
 *
 *       Filename:  io.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 17:23:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int main() {

  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      while ((c = getchar()) == ' ');
      putchar(' ');
    }
    if (c == EOF)
      break;
    putchar(c);
  }
  return 0;
}
