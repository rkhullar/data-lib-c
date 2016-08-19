/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/19/16
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

/*
 * @input  : length string array, delimiter, string array
 * @output : joined string
 */
static string* string_join(unsigned int n, string *d, string *a[])
{
  string **t = a, *s; char *m, *c;
  unsigned int ls[n], l, x, y=0;
  // find total lenght of new string
  for(x = 0; x < n; x++)
  {
    ls[x] = a[x]->length;
    l += ls[x];
    t++;
  }
  l += (n-1)*d->length + 1;
  // create output string
  s = string_mllc("");
  m = (char*) malloc(l*sizeof(char));
  for(x = 0; x < n; x++)
  {
    // add chars from one input string
    c = a[x]->ptr;
    while(*c)
      m[y++] = *c++;
    // add chars from delimiter
    c = d->ptr;
    while(*c && y < l-1)
      m[y++] = *c++;
  }
  m[y] = '\0'; // terminator
  s->ptr = m;
  s->length = l-1;
  return s;
}

//}}}
