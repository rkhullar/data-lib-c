/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/15/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "node.h"

//{{{
StringFunc node_gstr;
TestFunc node_test;
//}}}

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

extern const char * node_str(node *o)
{
  //char *p = node_gstr(o->data);
  //printf("s: %s\n", p);
  //return p;
  return node_gstr(o->data);
}

extern void node_print(node *o)
{
  //printf("%s\n", p);
  //char *p = node_str(o);
  printf("%s\n", node_str(o));
}

//}}}

//{{{

extern node_class node_clazz()
{
  node_class c;
  c.init  = &node_init;
  c.mllc  = &node_mllc;
  c.str   = &node_str;
  c.print = &node_print;
  return c;
}

//}}}
