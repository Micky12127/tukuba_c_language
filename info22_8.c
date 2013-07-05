// 筑波大学院過去入試問題平成22年8月

#include <stdio.h>
#include <stdlib.h>

struct list {
  int data;
  struct list *next;
};

struct list *head = NULL;

int sum_list();
void insert_list(int x);
void delete_list(int x);

int main() {
  int a[10] = {3, 2, 5, 9, 1, 10, 8, 6, 7, 4};
  int i;
  struct list *p;

  for (i = 0; i < 10; i++) {
    insert_list(a[i]);
  }

  printf("<insert_list関数（昇順バージョン）>\n");

  for (p = head; p != NULL; p = p->next) {
    printf("%d\n", p->data);
  }

  printf("<sum_list関数>\n");
  printf("%d\n", sum_list());

  delete_list(3);

  printf("<delete_list関数>\n");

  for (p = head; p != NULL; p = p->next) {
    printf("%d\n", p->data);
  }
}

int sum_list() {
  struct list *p;
  int sum;

  sum = 0;
  p = head;
  while (p != NULL) {
    sum += p->data;
    p = p->next;
  }

  return sum;
}

void insert_list(int x) {
  struct list *p, *q, *t;

  q = NULL;
  for (p = head; p != NULL; p = p->next) {
    if (p->data >= x) // ここの条件をif (p->data <= x)にすれば降順になる
      break;
    q = p;
  }

  t = (struct list *) malloc(sizeof(struct list));
  t->data = x;
  
  if (q == NULL)
    head = t;
  else
    q->next = t;
  t->next = p;
}

void delete_list(int x) {
  struct list *p, *q;

  q = NULL;
  for (p =head; p != NULL; p = p->next) {
    if (p->data == x) {
      if (q == NULL)
        head = p->next;
      else
        q->next = p->next;
      free(p);
      return;
    }
    q = p;
  }
}
