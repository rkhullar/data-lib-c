/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/14/16
 */

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct node node;
typedef struct node_class node_class;

struct node {
  T data;
  node *prev;
  node *next;
};

struct node_class
{
  node   (*init)  (T x);
  node * (*mllc)  (T x);
  char * (*gstr)  (T x);
  char * (*str)   (node_class *kls, node *self);
  void   (*print) (node_class *kls, node *self);
  //void   (*insert)(node *self, T x);
};

extern node_class node_clazz();
extern node node_init(T x);
extern node * node_mllc(T x);

static char * node_str   (node_class *kls, node *o);
static void   node_print (node_class *kls, node *o);

#endif //LINKED_LIST_NODE_H
