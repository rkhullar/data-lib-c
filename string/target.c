/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/18/16
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

int main()
{
  //test01();
  test02();
  return 0;
}
