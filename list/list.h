/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  01/31/16
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

typedef struct list list;
typedef struct list_c list_c;

struct list
{
    int size;
    node* head;
    node* tail;
    node* curr;
};

struct list_c
{
    list* (*init)(int data);
    void (*print)(list *self);
    void (*insert)(list *self, int d);
};

extern list_c* list_class();
extern list* list_init(int data);
static void list_print(list* o);

#endif //LINKED_LIST_H