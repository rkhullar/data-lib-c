/*
 * @author  :  Rajan Khullar
 * @created :  08/11/16
 * @updated :  08/11/16
 */

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

int main()
{
  // initialize list node class
  object_class *Object = object_clazz();

  // make some nodes
  object *a = Object->init();
  object *b = Object->init();

  // do what objects do
  Object->print(a);
  //puts(Object->str(a));

  // clean up
  free(a);
  free(b);
  free(Object);

  return 0;
}
