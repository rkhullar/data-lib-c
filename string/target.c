/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/19/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "string.h"

void test01()
{
  string_class String = string_clazz();
  string *s = String.mllc("hello world");
  String.print(s);
  int l = String.length(s);
  printf("%d\n", l);
  free(s);
}

void test02()
{
  string_class String = string_clazz();
  string *a = String.mllc("hello");
  string *b = String.mllc("helloo");
  bool t = String.equal(a, b);
  printf("%s = %s: %d\n", a->ptr, b->ptr, t);
  free(a); free(b);
}

void test03()
{
  string_class String = string_clazz();
  string *a[3];
  a[0] = String.mllc("hello");
  a[1] = String.mllc("cruel");
  a[2] = String.mllc("world");
  string *d  = String.mllc(" | ");
  string *px = String.mllc("[");
  string *sx = String.mllc("]");
  //string *s = String.join(3, a, d);
  string *s = string_join(.array=a, .n=3, .delim=d, .prefix=px, .suffix=sx);
  String.print(s);
  printf("N = %d\n", s->length);
  free(s);
  String.free(3, a);
}

int main()
{
  //test01();
  //test02();
  test03();
}
