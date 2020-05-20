#include <stdio.h>
#include "sorts.h"

Element create_int(int value)
{
  int * elem = malloc(sizeof(int));
  *elem = value;
  return (Element)elem;
}

Status is_number_lesser(Element a, Element b)
{
  return *(int *)a < *(int *)b;
}

void display_int(Element a)
{
  printf("%d\n", *(int *)a);
}

void perform_selection_sort(void)
{
  printf("Selection\n");
  List_ptr a = create_list();
  add_to_list(a, create_int(10));
  add_to_list(a, create_int(5));
  add_to_list(a, create_int(8));
  add_to_list(a, create_int(2));
  selection_sort(a, &is_number_lesser);
  display_list(a, &display_int);
}

void perform_bubble_sort(void)
{
  printf("Bubble\n");
  List_ptr a = create_list();
  add_to_list(a, create_int(10));
  add_to_list(a, create_int(5));
  add_to_list(a, create_int(8));
  add_to_list(a, create_int(2));
  bubble_sort(a, &is_number_lesser);
  display_list(a, &display_int);
}

void perform_insertion_sort(void)
{
  printf("Bubble\n");
  List_ptr a = create_list();
  add_to_list(a, create_int(10));
  add_to_list(a, create_int(5));
  add_to_list(a, create_int(8));
  add_to_list(a, create_int(2));
  insertion_sort(a, &is_number_lesser);
  display_list(a, &display_int);
}

int main(void) {
  perform_selection_sort();
  perform_bubble_sort();
  perform_insertion_sort();
  return 0;
}