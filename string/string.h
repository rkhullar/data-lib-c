/*
 * @author  :  Rajan Khullar
 * @created :  08/18/16
 * @updated :  08/19/16
 */

#ifndef STRING_H
#define STRING_H

#define string_join(...) string_join_wrap((string_join_args){__VA_ARGS__});

typedef struct
{
  char *ptr;
  unsigned int length;
} string;

typedef struct
{
  string   (*init)  (const char*);
  string * (*mllc)  (const char*);
  void     (*free)  (unsigned int, string *a[]);
  unsigned int (*length)(string *);
  void     (*print) (string*);
  bool     (*equal) (string*, string*);
  string * (*join)  (unsigned int n, string *a[], string *d, string *px, string *sx);
} string_class;


typedef struct
{
  unsigned int n;
  string **array;
  string *delim;
  string *prefix;
  string *suffix;
} string_join_args;

extern string_class string_clazz();

extern string   string_init(const char*);
extern string * string_mllc(const char*);
extern void string_free(unsigned int, string *a[]);

static void string_print(string*);
static unsigned int string_length(string*);
static bool string_equal(string*, string*);

static string* string_join_base(unsigned int n, string *a[], string *d, string *sx, string *fx);
extern string* string_join_wrap(string_join_args args);

#endif
