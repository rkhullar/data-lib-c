/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/18/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "string.h"

//{{{
extern string_class string_clazz()
{
  string_class c;
  c.init   = &string_init;
  c.mllc   = &string_mllc;
  c.length = &string_length;
  c.print  = &string_print;
  c.equal  = &string_equal;
  c.join   = &string_join;
  return c;
}
//}}}

//{{{
extern string string_init(const char *str)
{
  string o;
  o.ptr = (char*) str;
  o.length = string_length(&o);
  return o;
}

extern string * string_mllc(const char* str)
{
  string *o = (string*) malloc(sizeof(string));
  if(o == NULL) exit(1);
  *o = string_init(str);
  return o;
}

static unsigned int string_length(string* o)
{
  char *c = o->ptr;
  unsigned int l = 0;
  while(*c++) l++;
  o->length = l;
  return l;
}

static void string_print(string* o)
{
  printf("%s\n", o->ptr);
}

static bool string_equal(string* a, string* b)
{
  char *x = a->ptr; char *y = b->ptr;
  while(*x != '\0' && *y != '\0')
    if(*x++ != *y++)
    return false;
  return *x == *y;
}

static string* string_join(string *a[])
{
  return string_mllc("join");
}

//}}}
