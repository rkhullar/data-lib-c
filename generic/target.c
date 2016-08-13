/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/13/16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "generic.h"

int main()
{
  generic_class Object = generic_clazz();
  T *ptr = Object.mllc();
  Object.print(ptr);
  free(ptr);
  return 0;
}
