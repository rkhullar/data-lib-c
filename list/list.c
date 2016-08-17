/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/13/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "node.h"
#include "list.h"

//{{{
//}}}

//{{{

extern list list_init()
{
  list o;
  o.size = 0;
  o.head = NULL;
  o.tail = NULL;
  o.curr = NULL;
  return o;
}

extern list * list_mllc()
{
  list *o = (list*) malloc(sizeof(list));
  if(o == NULL) exit(1);
  *o = list_init();
  return o;
}

static void list_insert(list *o, T x)
{
  node_class Node = node_clazz();
  node *n = Node.mllc(x);
  o->size = 1;
  o->head = n;
  o->tail = n;
  o->curr = n;
}

static char * list_str(list *o)
{
  return "hello world";
}
//}}}

static void list_print(list *o)
{
  printf("%s\n", list_str(o));
}

//{{{

extern list_class list_clazz()
{
  list_class c;
  c.init   = &list_init;
  c.mllc   = &list_mllc;
  c.str    = &list_str;
  c.print  = &list_print;
  c.insert = &list_insert;
  return c;
}

//}}}
