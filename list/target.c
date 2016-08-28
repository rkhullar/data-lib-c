/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/28/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "node.h"
#include "list.h"
#include "misc.h"

node_class Node;
list_class List;

void setup()
{
  node_gstr = &itoa;
  node_geq = &ieq;
  Node = node_clazz();
  List = list_clazz();
}

void test01()
{
  node *ptr = Node.mllc(42);
  Node.print(ptr);
  free(ptr);
}

void test02()
{
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
  list *l = List.mllc();
  for(int i=0; i<10; i++)
    List.insert(l, -1, i);
  List.print(l);
  List.free(l);
}

int main()
{
  setup();
  //test01();
  //test02();
  //test03();
  //test04();
  //test05();
  test06();
  return 0;
}
