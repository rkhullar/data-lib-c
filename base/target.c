/*
 * @author  :  Rajan Khullar
 * @created :  08/11/16
 * @updated :  08/12/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

int main()
{
  // initialize list node class
  object_class Object = object_clazz();

  // make some nodes
  object a = Object.init();
  object *b = Object.mllc();

  // do what objects do
  Object.print(&a);
  Object.print(b);

  // clean up
  free(b);

  return 0;
}
