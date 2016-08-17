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

void test01()
{
  node_gstr = &itoa;
  node_class Node = node_clazz();
  node *ptr = Node.mllc(42);
  Node.print(ptr);
  free(ptr);
}

void test02()
{
  list_class List = list_clazz();
  list l = List.init();
  printf("%p\n", l.head);
  List.insert(&l, 4);
  printf("%d\n", l.curr->data);
}

void test03()
{
  int x = -56666677;
  const char *s = itoa(x);
  printf("%d=>%s\n", x, s);
}

void test04()
{
  node_gstr = &itoa;
  node_geq = &ieq;
  list_class List = list_clazz();
  list *l = List.mllc();
  List.print(l);
  free(l);
}

int main()
{
  //test01();
  //test02();
  //test03();
  test04();
  return 0;
}
