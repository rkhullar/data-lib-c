/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/13/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "generic.h"

//{{{

extern T generic_init()
{
  T o;
  return o;
}

extern T * generic_mllc()
{
  T *o = (T*) malloc(sizeof(T));
  if(o == NULL) exit(1);
  return o;
}

static bool generic_eq(void *a, void *b)
{
  return a == b;
}

static int generic_cmp(void *a, void *b)
{
  if(a > b) return 1;
  if(a < b) return -1;
  return 0;
}

static char * generic_str(void *o)
{
  /*
  char str[10];
  char *ptr = str;
  sprintf(ptr, "%p", (void*) o);
  return ptr;
  */
  return (char*) o;
}

static void generic_print(void *o)
{
  //printf("%s\n", generic_str(o));
  printf("%p\n", (void*)generic_str(o));
}

static int generic_hash(void *o)
{
  return 0;
}

//}}}

//{{{

extern generic_class generic_clazz()
{
  generic_class c;
  c.init  = &generic_init;
  c.mllc  = &generic_mllc;
  c.eq    = &generic_eq;
  c.cmp   = &generic_cmp;
  c.str   = &generic_str;
  c.print = &generic_print;
  c.hash  = &generic_hash;
  return c;
}

//}}}
