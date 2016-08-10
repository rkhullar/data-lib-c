/*
 * @author  :  Rajan Khullar
 * @created :  01/31/16
 * @updated :  01/31/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//{{{

extern node* node_init(int data)
{
    node* o = (node*) malloc(sizeof(node));
    if(o == NULL) exit(1);
    o->data = data;
    o->prev = NULL;
    o->next = NULL;
    return o;
}

static void node_print(node* o)
{
    printf("%d\n", o->data);
}

//}}}

//{{{

extern node_c* node_class()
{
    node_c* c = (node_c*) malloc(sizeof(node_c));
    if(c == NULL) exit(1);
    c->init = &node_init;
    c->print = &node_print;
    return c;
}

//}}}