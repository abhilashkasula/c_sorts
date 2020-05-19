#ifndef __SORTS_H__
#define __SORTS_H__

#include <stdio.h>
#include <stdlib.h>

typedef void *Object;

typedef struct
{
  Object *array;
  int length;
} Array;

typedef Array *Array_ptr;

typedef enum
{
  False,
  True
} Bool;

typedef Bool (*Predicate)(Object, Object);
typedef void (*Displayer)(Object);

Array_ptr create_array(int);
void display_array(Array_ptr, Displayer);
void selection_sort(Array_ptr, Predicate);

#endif
