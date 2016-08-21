/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/20/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "node.h"
#include "list.h"
#include "string.h"
#include "misc.h"

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
  int x = 0, n = o->size;
  string *a[n]; char *t;
  node *c = o->head;
  while(c)
  {
    t = node_gstr(c->data);
    a[x++] = string_mllc(t);
    c = c->next;
  }
  string *s = string_join(n, a, .prefix="[", .suffix="]");
  char *z = s->ptr;
  free(s);
  return z;
}
//}}}

static void list_print(list *o)
{
  char *p = list_str(o);
  printf("%s\n", p);
  free(p); // will fail if *p on stack
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
