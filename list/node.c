/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/13/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "node.h"

//{{{

extern node node_init(T x)
{
  node o;
  o.data = x;
  o.prev = NULL;
  o.next = NULL;
  return o;
}

extern node * node_mllc(T x)
{
  node *o = (node*) malloc(sizeof(node));
  if(o == NULL) exit(1);
  *o = node_init(x);
  return o;
}

//}}}

//{{{

extern node_class node_clazz()
{
  node_class c;
  c.init  = &node_init;
  c.mllc  = &node_mllc;
  return c;
}

//}}}
