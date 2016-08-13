/*
 * @author  :  Rajan Khullar
 * @created :  08/11/16
 * @updated :  08/12/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

//{{{

extern object object_init()
{
  object o;
  return o;
}

extern object * object_mllc()
{
  object *o = (object*) malloc(sizeof(object));
  if(o == NULL) exit(1);
  return o;
}

static int object_eq(object *a, object *b)
{
  return a == b;
}

static int object_cmp(object *a, object *b)
{
  if(a > b) return 1;
  if(a < b) return -1;
  return 0;
}

static char * object_str(object *o)
{
  /*
  char str[10];
  char *ptr = str;
  sprintf(ptr, "%p", (void*) o);
  return ptr;
  */
  return (char*) o;
}

static void object_print(object *o)
{
  //printf("%s\n", object_str(o));
  printf("%p\n", (void*)object_str(o));
}

static int object_hash(object *o)
{
  return 0;
}

//}}}

//{{{

extern object_class object_clazz()
{
  object_class c;
  c.init  = &object_init;
  c.mllc  = &object_mllc;
  c.eq    = &object_eq;
  c.cmp   = &object_cmp;
  c.str   = &object_str;
  c.print = &object_print;
  c.hash  = &object_hash;
  return c;
}

//}}}
