// 筑波大学院過去入試問題平成25年8月

#include <stdio.h>
#include <string.h>

#define NUM_CHAR 128
int skip[NUM_CHAR];
int simple_match(char *text, char *pattern);
int faster_match(char *text, char *pattern, int n);
int calc_skip(char *pattern);

int main() {
  char *text = "XYXZde0XZZkWXYZ";
  char *pattern = "WXYZ";
  int n = strlen(text);

  printf("%d\n", simple_match(text, pattern));
  printf("%d\n", faster_match(text, pattern, n));
}

int simple_match(char *text, char *pattern) {
  int i = 0, j = 0;
  while (text[i] != '\0') {
    if (text[i] != pattern[j]) {
      i++;
      j = 0;
    } else if (pattern[j + 1] == '\0')
      return i - j;
    else
      i++, j++;
  }
  return -1;
}

int faster_match(char *text, char *pattern, int n) {
  int m = calc_skip(pattern) - 1;
  int i = m, j;

  while (i < n) {
    j = m;
    while (j >= 0) {
      printf("j = %d\n", j);
      printf("i = %d\n", i);
      if (text[i] == pattern[j]) {
        if (j == 0)
          return i;
        i--, j--;
      } else
        break;

    }
    i = i + skip[text[i]];
  }
  return -1;
}

int calc_skip(char *pattern) {
  int i, m;
  m = strlen(pattern);
  for (i = 0; i < NUM_CHAR; i++)
    skip[i] = m;
  for (i = 0; i < m; i++)
    skip[pattern[i]] = m - i - 1;
  return m;
}
