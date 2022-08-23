/*
 * =====================================================================================
 *
 *       Filename:  histogram.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 20:42:35
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
  int c, i, j, ntotal;
  int nchars[26];
  ntotal = 0;

  for(i = 0; i < 26; i++)
    nchars[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {     // assume lower case
      nchars[c - 'a']++;
      ntotal++;
    }
  }

  printf("Histogram of characters:\n");
  for (i = 0; i < 26; i++) {
    printf("%c (%.0f%%): ", 'a'+i, (100.0/(double)ntotal)*nchars[i]);
    for (j = 0; j < nchars[i]; j++)
      printf("|");
    printf("\n");
  }

  return 0;
}
