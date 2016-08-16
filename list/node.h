/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/15/16
 */

 #include "macros.h"

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct node node;
typedef struct node_class node_class;

typedef char * (*StringFunc)(T);
typedef int (*TestFunc)(void);

struct node {
  T data;
  node *prev;
  node *next;
};

struct node_class
{
  node   (*init)  (T x);
  node * (*mllc)  (T x);
  char * (*str)   (node *self);
  void   (*print) (node *self);
  //void   (*insert)(node *self, T x);
};

extern node_class node_clazz();

extern node   node_init(T x);
extern node * node_mllc(T x);

static char * node_str   (node *o);
static void   node_print (node *o);

extern StringFunc node_gstr;
extern int (*node_test)(void);

#endif //LINKED_LIST_NODE_H
