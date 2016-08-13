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

int main()
{
  node_class Node = node_clazz();
  node *ptr = Node.mllc(5);
  printf("%d\n", ptr->data);
  free(ptr);
  return 0;
}
