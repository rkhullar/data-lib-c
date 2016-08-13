/*
 * @author  :  Rajan Khullar
 * @created :  08/11/16
 * @updated :  08/12/16
 */

#ifndef OBJECT_H
#define OBJECT_H

typedef struct object {} object;

typedef struct object_class
{
  object   (*init)  ();
  object * (*mllc)  ();
  int      (*eq)    (object *a, object *b);
  int      (*cmp)   (object *a, object *b);
  char   * (*str)   (object *self);
  void     (*print) (object *self);
  int      (*hash)  (object *self);
} object_class;

extern object_class object_clazz();

extern object   object_init();
extern object * object_mllc();

static int    object_eq    (object *a, object *b);
static int    object_cmp   (object *a, object *b);
static char * object_str   (object *o);
static void   object_print (object *o);
static int    object_hash  (object *o);

#endif //OBJECT_H
