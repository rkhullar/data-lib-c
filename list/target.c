/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/14/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "node.h"
#include "list.h"
#include "misc.h"

void test1()
{
  node_gstr = &itoa;
  node_class Node = node_clazz();
  node *ptr = Node.mllc(42);
  Node.print(ptr);
  free(ptr);
}

void test2()
{
  list_class List = list_clazz();
  list l = List.init();
  printf("%p\n", l.head);
  List.insert(&l, 4);
  printf("%d\n", l.curr->data);
}

void test3()
{
  int x = -56666677;
  const char *s = itoa(x);
  printf("%d=>%s\n", x, s);
}

int main()
{
  test1();
  //test2();
  //test3();
  return 0;
}
