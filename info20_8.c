// 筑波大学大学院CS専攻高度IT専修プログラムコース入試過去問題平成20年8月

#include <stdio.h>
#include <stdlib.h>

/*
 * (1)
 * 以下に、リストを表示する関数 print() を示す。空欄を埋めて、プログラムを完成させなさい。
 *
 */

struct list {
  char *elem;
  struct list *next;
};

void print(struct list *p);
int length(struct list *p);
int length_r(struct list *p);
struct list *f(struct list *p, struct list *q);
struct list *cons(char *s, struct list *p);
struct list *safe_f(struct list *p, struct list *q);

int main()
{
  struct list *p1, *p2;
  
  p1 = cons("blue", cons("yellow", cons("red", NULL)));
  p2 = cons("black", cons("white", NULL));
  print(safe_f(p1, p1));
  printf("要素の合計-> %d \n", length_r(safe_f(p2, safe_f(p1, p1))));
}

void print(struct list *p)
{
  if (p == NULL)
    printf("[ ]\n");   /* empty list */
  else {
    printf("[ %s", p->elem);
    for (p = p->next; p != NULL; p = p->next)
      printf(", %s", p->elem);
    printf(" ]\n");
  }
}

/*
 * (2)
 * 以下はリストの要素数を求める関数 length() と、これを再帰呼び出しを用いて記述した
 * 関数 length_r() である。空欄を埋めて、プログラムを完成させなさい。
 * また、関数 length() と関数 length_r() はどちらが優れているのかを、実行速度とメモリ
 * 使用効率の観点から説明しなさい。
 *
 * => 再帰関数で自分自身を呼び出す際に、情報を一時的にメモリ空間上に保存し、
 * リターン値が帰ってきたときにメモリ空間上に一時的に保存したデータを利用する
 * ために引き出してくるので、リターン値が帰ってくるまではメモリを使用していることに
 * なるため、関数 length_r() より 関数 length() の方が優れていると言える。
 * 
 */

int length(struct list *p)
{
  int n = 0;
  while (p != NULL) {
    n++;
    p = p->next;
  }
  return n;
}

int length_r(struct list *p)
{
  if (p == NULL)
    return 0;
  else
    return 1 + length_r(p->next);
}

/*
 * (3)
 * 以下のプログラムに関する設問に答えなさい。なお、関数 malloc() は指定されたバイト数の
 * メモリを割り当て、そのポインタを返す関数であり、メモリの割り当ては常に成功するものとする。
 *
 */

struct list *f(struct list *p, struct list *q)
{
  struct list *pt = p;
  if (p == NULL)
    return q;
  while (pt->next != NULL)
    pt = pt->next;
  pt->next = q;
  return p;
}

struct list *cons(char *s, struct list *p)
{
  struct list *t;
  t = malloc(sizeof (struct list));
  t->elem = s;
  t->next = p;
  return t;
}

/*
 * (a) このプログラムの出力結果を示しなさい。
 * (b) main() 関数内の f(p1, p2) を f(p1, p1) として実行したところ、プログラムが停止
 *     しなくなった。この理由を説明しなさい。
 *     
 *     => f 関数は、渡された引数 p と q があり、p->next がNULLになっている p->next に
 *        q が指す場所にする。つまり、p と q が同じところを指していたら、p->next が
 *        NULLになっている場所が p が引数として渡されたときに指しているところと同様
 *        の場所を指すことになり、print関数内で引数として渡されたポインタをいくら取り出しても
 *        NULLになる場所が無いため、処理が終了しない。
 *
 * (c) 以下の関数 safe_f() は (b) の問題点を解決したプログラムである。空欄を埋めて、
 *     プログラムを完成させなさい。
 */

struct list *safe_f(struct list *p, struct list *q)
{
  struct list *pt = q;
  if (p == NULL) {
    if (q == NULL)
      return p;
    else
      return cons(pt->elem, safe_f(p, pt->next));
  }
  else
    return cons(p->elem, safe_f(p->next, q));
}
