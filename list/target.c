/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/20/16
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
  List.insert(&l, 0, 4);
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
  node_class Node = node_clazz();
  list_class List = list_clazz();
  list *l = List.mllc();
  node *n1, *n2, *n3;
  n1 = Node.mllc(1);
  n2 = Node.mllc(2);
  n3 = Node.mllc(3);
  l->head = n1; l->tail = n3; l->size = 3;
                 n1->next = n2;
  n2->prev = n1; n2->next = n3;
  n3->prev = n2;
  List.print(l);
  free(n1); free(n2); free(n3); free(l);
}

void test05()
{
  node_gstr = &itoa;
  node_geq = &ieq;
  list_class List = list_clazz();
  node_class Node = node_clazz();
  list *l = List.mllc();
  printf("%d\n", List.empty(l));
  node *n = Node.mllc(5);
  l->head = n; l->tail = n; l->size = 1;
  printf("%d\n", List.empty(l));
  List.print(l);
  free(n); free(l);
}

void test06()
{
  node_gstr = &itoa;
  node_geq = &ieq;
  list_class List = list_clazz();
  list *l = List.mllc();
  for(int i=0; i<10; i++)
    List.insert(l, -1, i);
  List.print(l);
  List.free(l);
}

int main()
{
  //test01();
  //test02();
  //test03();
  //test04();
  //test05();
  test06();
  return 0;
}
