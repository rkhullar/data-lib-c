/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/17/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "node.h"
#include "list.h"
#include "misc.h"

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
  int x = 1, n = o->size;
  char *s; char *a[n+2];
  node *t = o->head;
  while(t != NULL)
  {
    a[x++] = node_gstr(t->data);
    t = t->next;
  }
  a[0] = "["; a[n+1] = "]";
  printf("%p\n", (void*) s);
  join(s, a);
  printf("%p\n", (void*) s);
  return s;
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
