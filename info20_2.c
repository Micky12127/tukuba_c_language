// 筑波大学大学院CS専攻高度IT専修プログラム平成20年2月

#include <stdio.h>
#include <stdlib.h>

void is(int sz, int d[]);
void in(int dt, int *val);
int dl(int *val);
void hs(int sz, int d[]);

int main()
{
  int size = 10;
  int d[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int i;

  printf("<関数実行前>\n");
  for (i = 0; i < size; i++)
    printf("d[%d] == %d\n", i, d[i]);

  hs(size, d);

  printf("\n<関数実行後>\n");
  for (i = 0; i < size; i++)
    printf("d[%d] == %d\n", i, d[i]);
}

void is(int sz, int d[])
{
  int i, j, m;
  int counter = 0;

  for (i = 1; i < sz; i++) {
    m = d[i];
    for (j = i - 1; j >= 0 && d[j] >= m; j--) {
      counter++;
      d[j + 1] = d[j];
    }
    d[j + 1] = m;
  }

  printf("\ncounter == %d\n", counter);

}

/*
 *
 * (1)
 * (a) 空欄を埋めて、プログラムを完成させなさい。
 * (b) 配列 d[] の要素がどのような場合に、プログラム中の d[j] >= m を実行する回数が
 *     最も多くなるかを説明しなさい。
 *     => 配列の要素が降順だった場合。
 * (c) sz が n のとき、d[j] >= m の最大実行回数を求めなさい。
 *     => 1 〜 (sz - 1)までの和になるため、n(n - 1) / 2 になる。
 * (d) プログラムを1箇所変更し、降順に整列する関数にしなさい。
 *     for文の d[j] >= m の箇所を d[j] <= m に変更する。
*/

void in(int dt, int *val)
{
  int i;

  val[0]++;
  for (i = val[0]; i > 1 && dt < val[i / 2]; i = i / 2)
    val[i] = val[i / 2];
  val[i] = dt;
}

int dl(int *val)
{
  int i = 1, j, ret = val[i];

  while (i <= val[0] / 2) {
    j = 2 * i;
    if (j + 1 < val[0] && val[j + 1] < val[j])
      j++;
    if (val[val[0]] < val[j])
      break;
    val[i] = val[j];
    i = j;
  }
  val[i] = val[0];
  val[0]--;
  return ret;
}

void hs(int sz, int d[])
{
  int i, *val;

  val = malloc(sizeof(int) * (sz + 1));
  val[0] = 0;

  for (i = 0; i < sz; i++)
    in(d[i], val);

  /* (A) */

  for (i = 0; i < sz; i++)
    d[i] = dl(val);
}

/*
 * (2)
 * (a) sz が4、d[] が {2, 0, 3, 1} だったとする。このとき、関数 hs() の (A) の時点に
 *     おける val[0] から val[4] の値を示しなさい。
 *
 *     val[0] => 4
 *     val[1] => 0
 *     val[2] => 1
 *     val[3] => 3
 *     val[4] => 2
 *
 * (b) 空欄を埋めて、プログラムを完成させなさい。
 * (c) 配列の要素が十分に大きいとする。このとき、比較回数の観点から、一般に、関数 is()
 *     と関数 hs() ではどちらが高速に動作するか。その理由とともに説明しなさい。
 * 
 */
