#ifndef __SORTS_H__
#define __SORTS_H__

#include "linkedlist.h"

typedef Status (*Sort_predicate)(Element, Element);

void selection_sort(List_ptr, Sort_predicate);
void bubble_sort(List_ptr, Sort_predicate);
void insertion_sort(List_ptr, Sort_predicate);

#endif
