/*
 * @author  :  Rajan Khullar
 * @created :  08/14/16
 * @updated :  08/18/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "misc.h"

extern bool ieq(int a, int b)
{
  return a == b;
}

extern char * itoa(int x)
{
  unsigned int l = snprintf(NULL, 0, "%d", x) + 1;
  char *p = (char*) malloc(l*sizeof(char));
  snprintf(p, l+1, "%d", x);
  return p;
}

extern char * join(unsigned int n, char *a[])
{
  unsigned int x=0, y=0, l=0;
  unsigned int ls[n];
  for(x = 0; x < n; x++)
  {
    ls[x] = strlen(a[x]);
    l += ls[x];
  }
  l += 1;
  char *s = (char*) malloc(l*sizeof(char));
  for(x = 0; x < n; x++)
  {
    char *c = a[x];
    while(*c)
      s[y++] = *c++;
  }
  s[y] = '\0';
  return s;
}

extern bool string_eq(char *a, char *b)
{
  while(*a != '\0' && *a != '\0')
    if(*a++ != *b++)
      return false;
  return *a == *b;
}

extern void test(char *a[])
{
  unsigned int x = 0;
  while(!string_eq(*a, ""))
  {
    a++;
    x++;
  }
  printf("%d\n", x);
}
