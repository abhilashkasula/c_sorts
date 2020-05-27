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
  int swap_count = 1;
  for (int i = 0; swap_count != 0; i++)
  {
    swap_count = 0;
    for (int j = 1; j < void_array->length - i; j++)
    {
      if ((*predicate)(void_array->array[j], void_array->array[j - 1]))
      {
        swap_count++;
        Object temp = void_array->array[j];
        void_array->array[j] = void_array->array[j - 1];
        void_array->array[j - 1] = temp;
      }
    }
  }
}

void insertion_sort(Array_ptr void_array, Predicate predicate)
{
  for (int i = 1; i < void_array->length; i++)
  {
    for (int j = i; j > 0 && (*predicate)(void_array->array[j], void_array->array[j - 1]); j--)
    {
      Object temp = void_array->array[j];
      void_array->array[j] = void_array->array[j - 1];
      void_array->array[j - 1] = temp;
    }
  }
}

void quick_sort(Array_ptr void_array, int start_index, int last_index, Predicate predicate)
{
  if(start_index >= last_index) return;
  void * pivot = void_array->array[last_index];
  int pivot_position = 0;

  for(int i = 0; i < last_index; i++) {
    if((*predicate)(void_array->array[i], pivot)) {
      void * temp = void_array->array[i];
      void_array->array[i] = void_array->array[pivot_position];
      void_array->array[pivot_position] = temp;
      pivot_position++;
    }
  }
  
  void * temp = void_array->array[pivot_position];
  void_array->array[pivot_position] = void_array->array[last_index];
  void_array->array[last_index] = temp;
  
  quick_sort(void_array, start_index, pivot_position - 1, predicate);
  quick_sort(void_array,pivot_position + 1, last_index, predicate);
}
