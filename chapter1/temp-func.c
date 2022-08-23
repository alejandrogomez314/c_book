/*
 * =====================================================================================
 *
 *       Filename:  temp-func.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 23:08:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

double calc_celsius(double fahr) {
  return (5.0/9.0) * (fahr-32.0);  
}

int main() {
  double fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahr | celsius \n");
  printf("--------------\n");
  while (fahr <= upper) {
    celsius = calc_celsius(fahr);
    printf("%5.0f|%8.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}




