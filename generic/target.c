/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  01/31/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
  // initialize list node class
  node_class* Node = node_class_init();

  // make some nodes

  int da = 21;
  char db[] = "hello";

  node* a = Node->init(&da);
  node* b = Node->init(db);

  // do what nodes do
  Node->print(a);
  Node->print(b);

  // clean up
  free(a);
  free(b);
  free(Node);

  return 0;
}
