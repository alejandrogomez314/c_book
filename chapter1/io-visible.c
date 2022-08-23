/*
 * =====================================================================================
 *
 *       Filename:  io-visible.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 17:43:46
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
      puts("\\t");
    } else if (c == '\b') {
      puts("\\b");
    } else if (c == '\\') {
      puts("\\");
    } else {
      putchar(c);
    }
  }
  return 0;
}
