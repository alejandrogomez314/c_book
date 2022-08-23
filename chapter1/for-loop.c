/*
 * =====================================================================================
 *
 *       Filename:  for-loop.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/15/2022 05:34:36
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
  int fahr;

  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
  return 0;
}
