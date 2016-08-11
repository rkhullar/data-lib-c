/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  08/10/16
 */

#ifndef OBJECT_NODE_H
#define OBJECT_NODE_H

typedef struct node node;
typedef struct node_class node_class;

struct node
{
  int data;
};

struct node_class
{
  node* (*init)(int data);
  void (*print)(node *self);
};

extern node_class* node_class_init();
extern node* node_init(int data);
static void node_print(node* o);

#endif //OBJECT_NODE_H
