// 筑波大学大学院CS専攻高度IT専修プログラムコース平成19年度2月

/*
 * 2つの関数 push() と pop() で操作するスタック（stack）を考える。push() は、スタックに
 * 要素を追加する関数である。pop() は、スタックから要素を取り出す関数である。ただし、
 * pop() は、スタックが空の時、エラーになるが、この問題ではエラーが起きないものとする。
 * 整数を保持することができるスタックをリンクトリストを用いて実現する。以下の図は、
 * そのようなスタックを箱と矢印で表現したものである。
 */

/*
 * (1) 以下は、スタックに対して要素を追加する、C言語で記述されたプログラムである。
 * 　　空欄を埋めて、プログラムを完成させなさい。ただし、関数 malloc() は、指定された
 * 　　バイト数のメモリを割り当て、その番地を返す関数である。この問題では、メモリの
 * 　　割り当ては常に成功するものとする。定数 NULL は、どの要素も指していないポインタ
 * 　　を意味する。
 */

#include <stdio.h>
#include <stdlib.h>

struct element {
  struct element *link;
  int data;
};

struct element *sp = NULL;

void push(int data);
int pop();
void sub();
void mul();
void print();
void swap();
void negate();

int sp_count(); // spのサイズを返す関数（問題とは関係無い！！
void vision(); // spの中身が視覚的にみるための関数（問題とは関係無い！！）

/*
 * (2) 以下のプログラムで sub() は、スタックから整数を2個取り出し、その差をスタックに
 * 　　追加する関数である。関数 mul() は、スタックから整数を2個取り出し、その積を
 * 　　スタックに追加する関数である。print() は、スタックから整数を1個取り出し、その値を
 * 　　画面に表示する関数である。
 *
 * 次のような main() 関数が実行された時に、画面にどのような表示がなされるか。
 * int main() {
 *   push(10);
 *   push(20);
 *   push(30);
 *   mul();
 *   sub();
 *   print();
 * }
 */

int main()
{
  push(10);
  push(20);
  push(30);

  vision();

  printf("(2)の解答\n");
  printf(" => ");
  mul();
  sub();
  print();

  push(10);
  push(20);
  push(30);

  printf("\n(4)の解答\n");
  printf(" => ");
  negate();
  print();
  printf("\n");
}

void push(int data)
{
  struct element *e;
  e = (struct element *) malloc(sizeof(struct element));
  e->link = sp;
  e->data = data;
  sp = e;
}

int pop()
{
  struct element *target = sp;
  int target_data = target->data;

  sp = target->link;
  free((void *)target);
  return target_data;
}

void sub()
{
  int arg1, arg2, res;

  arg2 = pop();
  arg1 = pop();
  res = arg1 - arg2;
  push(res);
}

void mul()
{
  int arg1, arg2, res;

  arg2 = pop();
  arg1 = pop();
  res = arg1 * arg2;
  push(res);
}

void print()
{
  int data;

  data = pop();
  printf("%d\n", data);
}

/*
 * (3) 以下は、スタックの先頭の要素と2番目の要素を入れ替える、C言語で記述されたプログラム
 * 　　である。空欄を埋めて、プログラムを完成させなさい。
 */

void swap()
{
  int arg1, arg2;

  arg2 = pop();
  arg1 = pop();
  push(arg2);
  push(arg1);
}

/*
 * (4) 以下は、スタックの先頭の要素の符号を反転させる、C言語で記述されたプログラムである。
 * 　　空欄を埋めて、プログラムを完成させなさい。
 */

void negate()
{
  /*
  push(sp->data * 2);
  swap();
  // swap()していることから、(F) の答えは上記のようになるのが自然だが、
  // 実行結果から、考えると間違っている。
  */
  push(-1);
  swap();
  sub();
}

int sp_count() {
  struct element *copy_sp;
  int n = 0;

  for (copy_sp = sp; copy_sp != NULL; copy_sp = copy_sp->link)
    n++;
  return n;
}

void vision()
{
  struct element *copy_sp = sp;
  int i, sp_size = sp_count();

  printf("\n----------------------spの中身-----------------------\n\n");
  printf("   sp\n");
  printf("    |\n");
  printf("    |\n");

  for (i = 0; i < sp_size; i++) {
    if (i == 0)
      printf("    |      ----     ");
    else
      printf(" ----     ");
  }
  printf(" ------ \n");

  for (i = 0; i < sp_size; i++) {
    if (i == 0)
      printf("    |     |    |    ");
    else
      printf("|    |    ");
  }
  printf("|      |\n");

  for (i = 0; i < sp_size; i++) {
    if (i == 0)
      printf("     ---->| %d |--->", copy_sp->data);
    else
      printf("| %d |--->", copy_sp->data);
    copy_sp = copy_sp->link;
  }
  printf("| NULL |\n");

  for (i = 0; i < sp_size; i++) {
    if (i == 0)
      printf("          |    |    ");
    else
      printf("|    |    ");
  }
  printf("|      |\n");

  for (i = 0; i < sp_size; i++) {
    if (i == 0)
      printf("           ----     ");
    else
      printf(" ----     ");
  }
  printf(" ------ \n\n\n");

  printf("-----------------------------------------------------\n\n");
}
