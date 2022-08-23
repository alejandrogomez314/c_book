#include <stdio.h>
void shellsort(int[], int);

int s[] = {6, 8, 3, 2, 5, 4, 1, 9, 7, 0};

int main(void) {
  int i;
  for (i = 0; i < 10; i++)
    printf("%d ", s[i]);

  printf("\n");
  shellsort(s, 10);

  for (i = 0; i < 10; i++)
    printf("%d ", s[i]);

  printf("\n");
  return 0;
}

void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
}
