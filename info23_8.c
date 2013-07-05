// 筑波大学院入試過去問平成23年8月

#include <stdio.h>

#define N 100

typedef struct {
  int length;
  int digits[N];
} BigDecimal;

void intToBigDecimal(int i, BigDecimal *d);
void shiftLeftBigDecimal(BigDecimal *d);
// void strToBigDecimal(char *str, BigDecimal *d);

int main() {
  int number = 12345;
  int i;
  char *str;
  BigDecimal d;

  intToBigDecimal(number, &d);

  printf("変数number\n");
  printf("%d", number);
  printf("\n");

  printf("構造体BigDecimal\n");
  for (i = d.length; i > 0; i--) {
    printf("%d", d.digits[i - 1]);
  }

  printf("\n");

  shiftLeftBigDecimal(&d);

  printf("shiftLeftBigDecimal関数実行後\n");
  for (i = d.length; i > 0; i--) {
    printf("%d", d.digits[i - 1]);
  }

  printf("\n");

  str = "12345";

  printf("%d\n", *str);
}

void intToBigDecimal(int i, BigDecimal *d) {
  d->length = 0;
  do {
    d->digits[d->length] = i % 10;
    d->length++;
    i = i / 10;
  }while (i);
}

void shiftLeftBigDecimal(BigDecimal *d) {
  int i;
  for (i = d->length; i > 0; i--) {
    d->digits[i] = d->digits[i - 1];
  }

  if (d->length > 1 || d->digits[0] != 0) {
    d->length++;
  }

  d->digits[0] = 0;
}
/*
   void strToBigDecimal(char *str, BigDecimal *d) {
   intToBigDecimal(0, d);
   do {
   shiftLeftBigDecimal(d);
   d->digits[0] = ;
   str++;
   } while ();
   }
   */
