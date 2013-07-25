// 筑波大学大学院システム情報工学研究科CS専攻高度IT専修プログラム
// 過去入試問題平成24年8月

#include <stdio.h>

#define SIZE 100

unsigned char stack[SIZE];
int sp;

void init_stack(); // スタックを空にする
int push(unsigned char data);
// スタックに引数で与えられたデータ（data）を加える
// 成功した時には 1, スタックがオーバーフローした時には、-1 を返す
int pop();
// スタックからデータを取り出し、それを返す
// スタックが空の時（アンダーフローした時）には、-1 を返す
int depth(); // スタックに含まれているデータの数を返す
int balance(unsigned char *p);

int main()
{
  unsigned char *input_0 = "{a{()}}b";
  unsigned char *input_1 = "{a{(})}b";
  unsigned char *input_2 = "][";
  unsigned char *input_3 = "[]";

  init_stack();
  push('(');
  push('(');
  push('[');
  push('{');
  printf("%c\n", pop());
  printf("%c\n", pop());
  printf("%c\n", pop());
  printf("%c\n", pop());

  printf("\n");

  printf("%d\n", balance(input_0));
  printf("%d\n", balance(input_1));
  printf("%d\n", balance(input_2));
  printf("%d\n", balance(input_3));
}

void init_stack()
{
  sp = SIZE;
}

int push(unsigned char data)
{
  if (sp /* E */ <= 0 /* /E */) { /* stack overflow */
    return -1;
  }

  /* F */ sp--; /* /F */
  /* G */ stack[sp] /* /G */ = data;
  /* H */ /**/ /* /H */
  return 1;
}

int pop()
{
  unsigned char data;
  if (sp /* I */ >= SIZE /* /I */) { /* stack underflow */
    return -1;
  }

  /* J */ /**/ /* /J */
  data = /* K */ stack[sp]; /* /K */
  /* L */ sp++; /* /L */
  return data;
}

int depth()
{
  return /* M */ SIZE - sp; /* /M */
}

int balance(unsigned char *p)
{
  unsigned char c;
  init_stack();
  for (; (c = *p) != '\0'; p++) {
    switch(c) {
      case '(':
      case '[':
      case '{':
        push(c);
        break;
      case ')':
        if (/* A */ pop() != '(' /* /A */) {
          return 0;
        }
        break;
      case '}':
        if (/* B */ pop() != '{' /* /B */) {
          return 0;
        }
        break;
      case ']':
        if (/* C */ pop() != '[' /* /C */) {
          return 0;
        }
        break;
      default:
        break;
    }
  }
  if (depth() /* D */ == 0 /* /D */) {
    return 1;
  }
  else {
    return 0;
  }
}
