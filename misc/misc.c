/*
 * @author  :  Rajan Khullar
 * @created :  08/14/16
 * @updated :  08/15/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "misc.h"

extern char * itoa(int x)
{
  int l = snprintf(NULL, 0, "%d", x) + 1;
  char *p = (char*) malloc(l*sizeof(char));
  snprintf(p, l+1, "%d", x);
  return p;
}
