/*
 * =====================================================================================
 *
 *       Filename:  detab.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/16/2022 06:18:39
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
    if (c == '\t') {
      putchar(' ');
      putchar(' ');
    } else {
      putchar(c);
    }
  }
  return 0;
}
