/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/21/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "string.h"

#include "node.h"
#include "list.h"

//{{{

extern list list_init()
{
  list o;
  o.size =  0;
  o.x    = -1;
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

extern void list_free(list *o)
{
  node *c = o->head;
  while(c->next)
  {
    c = c->next;
    free(c->prev);
  }
  free(c);
  free(o);
}

static bool list_empty(list *o)
{
  return o->head == NULL && o->tail == NULL;
}

static void list_insert(list *o, int x, T d)
{
  node_class Node = node_clazz();
  node *n, *p;
  if(list_empty(o))
  {
    list_reset(o, d);
    return;
  }
  if(x == -1)
  {
    n = Node.mllc(d); p = o->tail;
    p->next = n; n->prev = p;
    o->tail = n; o->curr = n;
    o->size++;
  }
}

static void list_reset(list *o, T d)
{
  node_class Node = node_clazz();
  node *n = Node.mllc(d);
  o->head = n;
  o->tail = n;
  o->curr = n;
  o->size = 1;
  o->x    = 0;
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
  c.free   = &list_free;
  c.str    = &list_str;
  c.print  = &list_print;
  c.empty  = &list_empty;
  c.insert = &list_insert;
  return c;
}

//}}}
