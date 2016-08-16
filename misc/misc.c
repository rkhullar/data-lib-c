/*
 * @author  :  Rajan Khullar
 * @created :  08/14/16
 * @updated :  08/15/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "misc.h"

extern const char * itoa(int x)
{
  int l = snprintf(NULL, 0, "%d", x);
  char s[l+1];
  char *p = s;
  snprintf(p, l+1, "%d", x);
  printf("i: %s\n", p);
  return p;
}
