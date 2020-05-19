#include "sorts.h"

Array_ptr create_array(int length)
{
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->length = length;
  new_array->array = malloc(sizeof(Object) * length);
  return new_array;
}

void display_array(Array_ptr void_array, Displayer display)
{
  for (int i = 0; i < void_array->length; i++)
  {
    (*display)(void_array->array[i]);
  }
  printf("\n");
}

void selection_sort(Array_ptr void_array, Predicate predicate)
{
  for (int i = 0; i < void_array->length; i++)
  {
    int index = i;

    for (int j = i + 1; j < void_array->length; j++)
    {
      if ((*predicate)(void_array->array[j], void_array->array[index]))
      {
        index = j;
      }
    }

    Object temp = void_array->array[i];
    void_array->array[i] = void_array->array[index];
    void_array->array[index] = temp;
  }
}

void bubble_sort(Array_ptr void_array, Predicate predicate)
{
  for(int i = 0; i < void_array->length; i++)
  {
    for(int j = 1; j < void_array->length - i; j++)
    {
      if((*predicate)(void_array->array[j], void_array->array[j - 1]))
      {
        Object temp = void_array->array[j];
        void_array->array[j] = void_array->array[j - 1];
        void_array->array[j - 1] = temp;
      }
    }
  }
}
