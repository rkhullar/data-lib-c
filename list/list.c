/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  01/31/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//{{{

extern list* list_init(int data)
{
    list* l = (list*) malloc(sizeof(list));
    if(l == NULL) exit(1);
    node* n = node_init(data);
    l->head = n;
    l->tail = n;
    l->curr = n;
    l->size = 1;
    return l;
}

static void list_print(list* l)
{
    printf("%d\n", l->curr->data);
}

//}}}

//{{{

extern list_c* list_class()
{
    list_c* c = (list_c*) malloc(sizeof(list_c));
    if(c == NULL) exit(1);
    c->init = &list_init;
    c->print = &list_print;
    return c;
}

//}}}