/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  01/31/16
 */

#ifndef LIST_NODE_H
#define LIST_NODE_H

typedef struct node node;
typedef struct node_c node_c;

struct node
{
    int data;
    node* prev;
    node* next;
};

struct node_c
{
    node* (*init)(int data);
    void (*print)(node *self);
};

extern node_c* node_class();
extern node* node_init(int data);
static void node_print(node* o);

#endif //LIST_NODE_H
