// 筑波大学大学院CS専攻高度IT専修プログラムコース過去前期入試問題平成19年8月

#include <stdio.h>
#include <stdlib.h>

#define M 10

struct element {
  struct element *link;
  int data;
};

struct queuehead {
  struct element *first;
  struct element *last;
};

struct queuehead pockets[M];
struct queuehead *qh;

void enqueue(struct queuehead *qh, int data);
int dequeue(struct queuehead *qh);
void radix_sort(struct queuehead *input, struct queuehead *output, int n);

int main() {
  int i, data, num[] = {52, 97, 74, 0, 37, 14, 57, 95}, size = 8;
  struct queuehead *input, *output;
  struct element *copy_element;

  input = (struct queuehead *) malloc(sizeof(struct queuehead));
  input->first = NULL;
  input->last = NULL;

  output = (struct queuehead *) malloc(sizeof(struct queuehead));
  output->first = NULL;
  output->last = NULL;

  printf("\n<基数整列法適用前>\n");
  printf("{ %d", num[0]);
  enqueue(input, num[size - 1]);
  for (i = 1; i < size; i++) {
    enqueue(input, num[size - i - 1]);
    printf(", %d", num[i]);
  }
  printf(" }\n\n");

  radix_sort(input, output, 0);
  input = output;
  radix_sort(input, output, 1);

  printf("<基数整列法適用後>\n");
  printf("{ %d", dequeue(output));
  while ((data = dequeue(output)) >= 0)
    printf(", %d", data);
  printf(" }\n\n");

}

void enqueue(struct queuehead *qh, int data) {
  struct element *e;
  e = (struct element *) malloc(sizeof(struct element));
  e->link = qh->first;
  e->data = data;
  if (qh->first == NULL) {
    // 待ち行列が空の時の処理
    qh->first = e;
    qh->last = e;
  }
  else {
    qh->first = e;
  }
}

int dequeue(struct queuehead *qh) {
  int copy_data;
  struct element *copy_element;

  if (qh->last == NULL) {
    return -1;
  }
  else if (qh->first->link == NULL) {
    // 待ち行列の要素が最後の一つであるとき
    copy_data = qh->first->data;
    copy_element = qh->first;
    qh->first = NULL;
    qh->last = NULL;

    free((void *) copy_element);

    return copy_data;
  }
  else {
    copy_data = qh->last->data;

    for (copy_element = qh->first; copy_element->link != NULL; copy_element = copy_element->link)
      // 最後から2番目までポインタを移動

    qh->last = copy_element;
    qh->last->link = NULL;

    return copy_data;
  }
}

void radix_sort(struct queuehead *input, struct queuehead *output, int n) {
  int data, div, i;

  for (i = 0, div = 1; i < n; i++)
    div = div * M;
  while((data = dequeue(input)) >= 0) {
    i = (data / div) % M;
    enqueue(&pockets[i], data);
  }
  for (i = 0; i < M; i++) {
    while ((data = dequeue(&pockets[i])) >= 0) {
      enqueue(output, data);
    }
  }
}


