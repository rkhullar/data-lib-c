/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/10/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//{{{

extern node* node_init(void* data)
{
  node* o = (node*) malloc(sizeof(node));
  if(o == NULL) exit(1);
  o->data = data;
  return o;
}

static void node_print(node* o)
{
  printf("%p\n", o->data);
}

//}}}

//{{{

extern node_class* node_class_init()
{
  node_class* c = (node_class*) malloc(sizeof(node_class));
  if(c == NULL) exit(1);
  c->init = &node_init;
  c->print = &node_print;
  return c;
}

//}}}
