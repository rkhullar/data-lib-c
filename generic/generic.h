/*
 * @author  :  Rajan Khullar
 * @created :  08/13/16
 * @updated :  08/13/16
 */

#ifndef GENERIC_H
#define GENERIC_H

//#define T int

typedef struct generic_class
{
  T      (*init)  ();
  T    * (*mllc)  ();
  bool   (*eq)    (void *a, void *b);
  int    (*cmp)   (void *a, void *b);
  char * (*str)   (void *self);
  void   (*print) (void *self);
  int    (*hash)  (void *self);
} generic_class;

extern generic_class generic_clazz();

extern T   generic_init();
extern T * generic_mllc();

static bool   generic_eq    (void *a, void *b);
static int    generic_cmp   (void *a, void *b);
static char * generic_str   (void *o);
static void   generic_print (void *o);
static int    generic_hash  (void *o);

#endif //GENERIC_H
