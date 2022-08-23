/*
 * =====================================================================================
 *
 *       Filename:  temp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 05:22:07
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
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahr | celsius \n");
  printf("--------------\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%5.0f|%8.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
