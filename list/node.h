/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/16/16
 */

#include "macros.h"

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct node node;
typedef struct node_class node_class;

typedef char * (*StringFunc)(T);
typedef bool   (*EqualFunc)(T,T);

struct node {
  T data;
  node *prev, *next;
};

struct node_class
{
  node   (*init)  (T x);
  node * (*mllc)  (T x);
  char * (*str)   (node *self);
  void   (*print) (node *self);
};

extern node_class node_clazz();

extern node   node_init(T x);
extern node * node_mllc(T x);

static char * node_str   (node *o);
static void   node_print (node *o);

extern StringFunc node_gstr;
extern EqualFunc node_geq;

#endif //LINKED_LIST_NODE_H
