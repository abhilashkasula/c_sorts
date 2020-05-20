#include "sorts.h"

void selection_sort(List_ptr list, Sort_predicate predicate)
{
  Node_ptr p_walk = list->first;

  while (p_walk != NULL)
  {
    Node_ptr smaller = p_walk;
    Node_ptr next = p_walk->next;

    while (next != NULL)
    {
      if((*predicate)(next->element, smaller->element))
      {
        smaller = next;
      }
      next = next->next;
    }

    Element temp = p_walk->element;
    p_walk->element = smaller->element;
    smaller->element = temp;

    p_walk = p_walk->next;
  }
}

void bubble_sort(List_ptr list, Sort_predicate predicate)
{
  Node_ptr p_walk = list->first;
  int swap_count = 1;

  for(int i = 0; p_walk != NULL && swap_count != 0; i++)
  {
    swap_count = 0;
    Node_ptr next = list->first->next;

    for(int j = 1; j < list->length - i && next != NULL; j++)
    {
      if((*predicate)(next->element, next->prev->element))
      {
        swap_count++;
        Element temp = next->element;
        next->element = next->prev->element;
        next->prev->element = temp;
      }
      next = next->next;
    }
    
    p_walk = p_walk->next;
  }  
}

void insertion_sort(List_ptr list, Sort_predicate predicate)
{
  Node_ptr p_walk = list->first->next;

  while(p_walk != NULL)
  {
    Node_ptr prev = p_walk;
    while (prev->prev != NULL && (*predicate)(prev->element, prev->prev->element))
    {
      Element temp = prev->element;
      prev->element = prev->prev->element;
      prev->prev->element = temp;
      prev = prev->prev;
    }
    p_walk = p_walk->next;
  }
}
