#include <ctype.h>
#include <stdio.h>
#include <math.h>
#define MAXLINE 256

double atof(char[]);
int main(void) {
  FILE* fp = stdin;
  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  while ((linelen = getline(&line, &linecap, fp)) > 0)
    printf("%g\n", atof(line));
  return 0;
}

double atof(char s[]) {
  double coef, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (coef = 0.0; isdigit(s[i]); i++)
    coef = 10.0 * coef + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    coef = 10.0 * coef + (s[i] - '0');
    power *= 10.0;
  }
  
  coef = sign * coef / power;
  
  sign = 0;
  if (s[i] == 'e' || s[i] == 'E') {
    i++;  
    if (s[i] == '-') {
      i++;
      sign = 1;
    }
    power = pow(10, s[i] - '0');
    if (!sign)
      coef *= power;
    else
      coef /= power;
  }
  return coef;

}
