/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/13/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"
#include "list.h"

void test1()
{
  node_class Node = node_clazz();
  node *ptr = Node.mllc(5);
  printf("%d\n", ptr->data);
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

int main()
{
  //test1();
  test2();
  return 0;
}
