/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/13/16
 */

#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list
{
  int size;
  node* head;
  node* tail;
  node* curr;
} list;

typedef struct list_class
{
  list   (*init)   ();
  list * (*mllc)   ();
  void   (*print)  (list *self);
  void   (*insert) (list *self, T x);
} list_class;

extern list_class list_clazz();
extern list list_init();
extern list * list_mllc();

static void list_print(list *o);
static void list_insert(list *o);

#endif //LINKED_LIST_H
