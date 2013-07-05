// 筑波大学院過去入試問題平成21年2月

#include <stdio.h>

int array_size(int array[]);
void print_array(int a[], int n);
void insertion_sort(int a[], int n);
void shift(int a[], int first, int last);

void insertion_sort_d(int a[], int n, int d);
void shell_sort(int a[], int n);
void shift_d(int a[], int first, int last, int d);

int array1[] = {80, 35, 15, 40, 65};
int dim[] = {1, 2, 4};

int main() {
  printf("\n");
  printf("<ソート前>\n");
  print_array(array1, 5);
  printf("\n");

  shell_sort(array1, 5);

  printf("\n");
  printf("<ソート後>\n");
  print_array(array1, 5);
  printf("\n");
}

void print_array(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void insertion_sort(int a[], int n) {
  int w, j, i;
  if (n <= 1)
    return;

  for (i = 1; i < n; i++) {
    printf("i == %d: ", i);
    print_array(a, n);
    w = a[i];
    for (j = 0; j < i && a[j] < a[i]; j++)
      continue;
    shift(a, j, i);
    a[j] = w;
  }
  printf("i == %d: ", i);
  print_array(a, n);
}

void shift(int a[], int first, int last) {
  int p;
  for (p = last - 1; first <= p; p--) {
    a[p + 1] = a[p];
  }
}

void insertion_sort_d(int a[], int n, int d) {
  int w, i, j, k;
  if (n <= d)
    return;
  for (k = 0; k < n; k = k + 1) {
    printf("array1 == ");
    print_array(a, n);
    for (i = d + k; i < n; i = i + d) {
      w = a[i];
      for (j = k; j < i && a[j] < a[i]; j = j + d)
        continue;
      shift_d(a, j, i, d);
      a[j] = w;
    }
  }
}

void shell_sort(int a[], int n) {
  int l;

  for (l = sizeof(dim) / sizeof(dim[0]) - 1; 0 <= l; l--) {
    printf("dim == %d\n", dim[l]);
    insertion_sort_d(a, n, dim[l]);
  }
}

void shift_d(int a[], int first, int last, int d) {
  int q;
  for (q = last - d; first <= q; q -= d) {
    a[q + d] = a[q];
  }
}
