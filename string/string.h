/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/18/16
 */

#ifndef STRING_H
#define STRING_H

typedef struct string {
  char *ptr;
  unsigned int length;
} string;

typedef struct string_class
{
  string   (*init)  (const char*);
  string * (*mllc)  (const char*);
  unsigned int (*length)(string *);
  void     (*print) (string*);
  bool     (*equal) (string*, string*);
  string * (*join)  (string *a[]);
} string_class;

extern string_class string_clazz();

extern string   string_init(const char*);
extern string * string_mllc(const char*);

static void string_print(string*);
static unsigned int string_length(string*);
static bool string_equal(string*, string*);
static string* string_join(string *a[]);

#endif
