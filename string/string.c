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
  c.free   = &string_free;
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

extern void string_free(unsigned int n, string *a[])
{
  string **t = a;
  for(unsigned int x = 0; x < n; x++)
  {
    free(*t);
    t++;
  }
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

static string* string_join(unsigned int n, string *d, string *a[])
{
  string **t = a, *s; char *m, *c;
  unsigned int ls[n], dl, l=0, x=0, y=0;
  dl = string_length(d);
  for(; x < n; x++)
  {
    ls[x] = string_length(a[x]);
    l += ls[x];
    t++;
  }
  l += dl*(n-1) + 1;
  s = string_mllc("");
  m = (char*) malloc(l*sizeof(char));
  for(x = 0; x < n; x++)
  {
    c = a[x]->ptr;
    while(*c)
      m[y++] = *c++;
    c = d->ptr;
    while(*c && y < l-1)
      m[y++] = *c++;
  }
  m[y] = '\0';
  s->ptr = m;
  s->length = l-1;
  return s;
}

//}}}
