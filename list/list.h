/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/21/16
 */

#include "macros.h"
#include "node.h"

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct
{
  unsigned int size, x;
  node *head, *tail, *curr;
} list;

typedef struct
{
  list   (*init)   ();
  list * (*mllc)   ();
  char * (*str)    (list*);
  void   (*print)  (list*);
  bool   (*empty)  (list*);
  void   (*insert) (list*, int x, T d);
} list_class;

extern list_class list_clazz();
extern list list_init();
extern list * list_mllc();

static char * list_str    (list*);
static void   list_print  (list*);
static bool   list_empty  (list*);
static void   list_insert (list*, int x, T d);

#endif //LINKED_LIST_H
