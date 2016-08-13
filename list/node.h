/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/13/16
 */

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct node node;

struct node {
  T data;
  node *prev;
  node *next;
};

typedef struct node_class
{
  node   (*init)(T x);
  node * (*mllc)(T x);
  //void   (*print)(node *self);
  //void   (*insert)(node *self, T x);
} node_class;

extern node_class node_clazz();
extern node node_init(T x);
extern node * node_mllc(T x);

//static void node_print(node *o);

#endif //LINKED_LIST_NODE_H
