/*
 * =====================================================================================
 *
 *       Filename:  count-chars.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 17:18:04
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
  int c, bl, ta, nl;

  nl = 0, bl = 0, ta = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      nl++;
    if (c == ' ')
      bl++;
    if (c == '\t')
      ta++;
  }
  printf("blanks: %d, tabs: %d, newlines: %d\n", bl, ta, nl);
  return 0;
}
