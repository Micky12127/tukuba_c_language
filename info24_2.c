// 筑波大学大学院システム情報工学研究科CS専攻高度IT専修プログラム
// 平成24年度2月過去入試問題

#include <stdio.h>
#include <stdlib.h>

#define N 8

int Adj[N][N] = {
         /* 0  1  2  3  4  5  6  7 */
  /* 0 */ { 0, 1, 1, 0, 0, 0, 0, 0 },
  /* 1 */ { 0, 0, 1, 0, 0, 1, 0, 0 },
  /* 2 */ { 0, 0, 0, 1, 0, 0, 0, 0 },
  /* 3 */ { 0, 0, 0, 0, 1, 0, 1, 0 },
  /* 4 */ { 0, 0, 0, 0, 0, 1, 0, 0 },
  /* 5 */ { 0, 0, 0, 0, 0, 0, 1, 0 },
  /* 6 */ { 0, 0, 0, 0, 0, 0, 0, 1 },
  /* 7 */ { 1, 0, 0, 0, 0, 0, 0, 0 }
};

struct element {
  struct element *next;
  int data;
};

struct queue {
  struct element *head;
  struct element *tail;
};

struct queue *make_queue();
void enqueue(struct queue *q, int data);
int dequeue(struct queue *q);
int is_empty(struct queue *q);
void destroy_queue(struct queue *q);
void traverse(int start, int goal);

int main()
{
  struct queue *q;
  q = make_queue();
  enqueue(q, 10);
  enqueue(q, 5);
  enqueue(q, 5);
  enqueue(q, 20);
  printf("%d, ", dequeue(q));
  printf("%d, ", dequeue(q));
  printf("%d, ", dequeue(q));
  printf("%d\n", dequeue(q));

  traverse(1, 0);
}

struct queue *make_queue()
{
  struct queue *q;
  q = (struct queue *) malloc(sizeof(struct queue));
  q->head = NULL;
  q->tail = NULL;
  return q;
}

int is_empty(struct queue *q)
{
  return ((q->head == NULL) ? 1 : 0);
}

int dequeue(struct queue *q)
{
  struct element *element;
  int data;
  if (is_empty(q)) {
    return -1;
  }
  element = q->head;
  q->head = element->next;
  data = element->data;
  if (q->head == NULL) {
    q->tail = NULL;
  }
  /* */
  free(element);
  return data;
}

void enqueue(struct queue *q, int data)
{
  struct element *element;

  element = (struct element *) malloc(sizeof(struct element));
  element->data = data;
  element->next = NULL;
  if (q->head == NULL) {
    q->head = element;
    q->tail = element;
  }
  else {
    q->tail->next = element;
    q->tail = element;
  }
}

void destroy_queue(struct queue *q)
{
  struct element *element;

  if (q->head == NULL) {
    free(q);
  }
  else {
    for (element = q->head; q->head != q->tail; element = q->head) {
      q->head = q->head->next;
      free(element);
    }
    element = q->head;
    q->head = NULL;
    q->tail = NULL;
    free(element);
    free(q);
  }
}

void traverse(int start, int goal)
{
  struct queue *q;
  int dist[N];
  int prev, node;

  for (node = 0; node < N; node++) {
    dist[node] = -1;
  }

  q = make_queue();
  dist[start] = 0;
  enqueue(q, start);
  printf("Start from Node %d\n", start);
  while (!is_empty(q)) {
    prev = dequeue(q);
    for (node = 0; node < N; node++) {
      if (Adj[prev][node] == 1) {
        if (dist[node] == -1) {
          dist[node] = dist[prev] + 1;
          printf("Visiting Node %d from Node %d, distance %d\n", node, prev, dist[node]);
          if (node == goal) {
            printf("Path found from Node %d to Node %d, distance %d\n",
                    start, goal, dist[node]);
            destroy_queue(q);
            return;
          }
          else {
            enqueue(q, node);
          }
        }
      }
    } /* end for */
  } /* end while */
  printf("No path found from %d to %d\n", start, goal);
  destroy_queue(q);
}
