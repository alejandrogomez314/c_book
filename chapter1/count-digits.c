/*
 * =====================================================================================
 *
 *       Filename:  count-digits.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 20:32:49
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
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; i++)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ndigit[c-'0']++;
    else if (c == ' ' || c == '\n' || c == '\t')
      nwhite++;
    else
      nother++;
  }

  printf("digits =");
  for (i = 0; i < 10; i++)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);

  return 0;
}
