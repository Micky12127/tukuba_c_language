// 筑波大学大学院CS専攻高度IT専修プログラムコース過去入試問題平成25年2月

#include <stdio.h>
#include <stdlib.h>

#define N 6
#define M 1000
typedef enum {FALSE = 0, TRUE = 1} Bool;
struct vertices {
  Bool Vertex[N];
  int Vcount;
};

void set_vertices(struct vertices *v, Bool b);
Bool remain(struct vertices *v);
Bool member(int x, struct vertices *v);
int select_min(int d[], struct vertices *v);
void add_vertex(int x, struct vertices *v);
void remove_vertex(int x, struct vertices *v);
void Dijkstra(int p, int w[N][N], int d[N]);

int main()
{
  int d[] = {0, 0, 0, 0, 0, 0};

  /* (1) */
  int w[N][N] = {
      /* 0  1  2  3  4  5 */
/* 0 */ {0, M, M, 60, M, 5},
/* 1 */ {5, 0, 6, M, 50, M},
/* 2 */ {M, M, 0, 5, M, M},
/* 3 */ {M, M, M, 0, 5, M},
/* 4 */ {30, M, 20, M, 0, M},
/* 5 */ {M, 40, M, M, 5, 0}
  };
  int i;
  struct vertices a;

  printf("(1)\n");
  printf("   A -> M\n");
  printf("   B -> 5\n");
  printf("   C -> 0\n");
  printf("   D -> M\n");
  printf("   E -> 5\n");

  printf("(2)\n");
  printf("   F -> v->Vcount\n");
  printf("   G -> v->Vertex[x]\n");

  Dijkstra(1, w, d);

  printf("\n");
  printf("   (b)\n");
  printf("       d[] == {");
  for (i = 0; i < N - 1; i++) {
    printf("%d, ", d[i]);
  }
  printf("%d}\n\n", d[i]);
}

void set_vertices(struct vertices *v, Bool b)
{
  int i;

  for (i = 0; i < N; i++) {
    v->Vertex[i] = b;
  }
  if (b == TRUE) {
    v->Vcount = N;
  }
  else {
    v->Vcount = 0;
  }
}

Bool remain(struct vertices *v)
{
  if (/* (F) */ v->Vcount /* \(F) */) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

Bool member(int x, struct vertices *v)
{
  return /* (G) */v->Vertex[x]/* /(G) */;
}

int select_min(int d[], struct vertices *v)
{
  int i, j, k = M;

  for (i = 0; i < N; i++) {
    if (v->Vertex[i]) {
      if (d[i] < k) {
        k = d[i];
        j = i;
      }
    }
  }

  return j;
}

void add_vertex(int x, struct vertices *v)
{
  v->Vertex[x] = TRUE;
  v->Vcount++;
}

void remove_vertex(int x, struct vertices *v)
{
  v->Vertex[x] = FALSE;
  if (0 < v->Vcount) {
    v->Vcount--;
  }
}

void Dijkstra(int p, int w[N][N], int d[N])
{
  int i, u, x, k;
  int j, m;
  struct vertices U, V;

  set_vertices(&V, FALSE);
  set_vertices(&U, TRUE);
  for (i = 0; i < N; i++) {
    d[i] = M;
  }
  d[p] = 0;

  printf("(3)\n");
  printf("   (a)\n");

  while (remain(&U)) {
    u = select_min(d, &U); /* (ア) */
    /* (3)(a) */
    printf("       u == %d\n", u);

    add_vertex(u, &V);
    remove_vertex(u, &U);
    for (x = 0; x < N; x++) {
      if (w[u][x] < M && member(x, &U)) {
        k = d[u] + w[u][x];
        if (k < d[x]) {
          d[x] = k;
        }
      }
    }
  }
}
