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
  node_c* Node = node_class();

  // make some nodes
  node* a = Node->init(2147483647);
  node* b = Node->init(2147483648);

  // do what nodes do
  Node->print(a);
  Node->print(b);

  // clean up
  free(a);
  free(b);
  free(Node);

  return 0;
}
