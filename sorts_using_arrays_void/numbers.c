#include "sorts.h"
#include <string.h>

Bool is_number_lesser_than(Object a, Object b)
{
  return *(int *)a < *(int *)b;
}

void display_number(Object data)
{
  printf("%d ", *(int *)data);
}

Object create_int(int value)
{
  int *element = malloc(sizeof(int));
  *element = value;
  return (Object)element;
}

Object create_char(char value)
{
  char *element = malloc(sizeof(char));
  *element = value;
  return (Object)element;
}

void display_char(Object data)
{
  printf("%c ", *(char *)data);
}

Bool is_char_lesser_than(Object a, Object b)
{
  return *(char *)a < *(char *)b;
}

void sort_chars(void)
{
  Array_ptr letters = create_array(7);
  letters->array[0] = create_char('g');
  letters->array[1] = create_char('e');
  letters->array[2] = create_char('h');
  letters->array[3] = create_char('b');
  letters->array[4] = create_char('d');
  letters->array[5] = create_char('f');
  letters->array[6] = create_char('a');

  display_array(letters, &display_char);
  selection_sort(letters, &is_char_lesser_than);
  display_array(letters, &display_char);
}

void sort_numbers(void)
{
  Array_ptr numbers = create_array(7);
  numbers->array[0] = create_int(10);
  numbers->array[1] = create_int(5);
  numbers->array[2] = create_int(8);
  numbers->array[3] = create_int(2);
  numbers->array[4] = create_int(13);
  numbers->array[5] = create_int(12);
  numbers->array[6] = create_int(1);

  display_array(numbers, &display_number);
  selection_sort(numbers, &is_number_lesser_than);
  display_array(numbers, &display_number);
}

int find_length(char *value)
{
  int length = 0;
  for (; value[length] != '\0'; length++)
    ;
  return length;
}

char *create_string(char *value)
{
  int length = find_length(value);
  char *string = malloc(sizeof(char) * length);
  memcpy(string, value, length);
  return string;
}

void display_string(Object data)
{
  printf("%s ", (char *)data);
}

Bool is_string_lesser_than(Object a, Object b)
{
  return strcmp((char *)a, (char *)b) < 0;
}

void sort_strings(void)
{
  Array_ptr strings = create_array(3);
  strings->array[0] = create_string("hi");
  strings->array[1] = create_string("abc");
  strings->array[2] = create_string("hill");
  display_array(strings, &display_string);
  selection_sort(strings, &is_string_lesser_than);
  display_array(strings, &display_string);
}

void perform_selection_sort(void)
{
  printf("Selection Sort\n");
  sort_chars();
  printf("\n");
  sort_numbers();
  printf("\n");
  sort_strings();
}

void perform_bubble_sort(void)
{
  Array_ptr numbers = create_array(7);
  numbers->array[0] = create_int(10);
  numbers->array[1] = create_int(5);
  numbers->array[2] = create_int(8);
  numbers->array[3] = create_int(2);
  numbers->array[4] = create_int(13);
  numbers->array[5] = create_int(12);
  numbers->array[6] = create_int(1);

  printf("\nBubble Sort\n");
  display_array(numbers, &display_number);
  bubble_sort(numbers, &is_number_lesser_than);
  display_array(numbers, &display_number);
}

void perform_insertion_sort(void)
{
  Array_ptr numbers = create_array(7);
  numbers->array[0] = create_int(10);
  numbers->array[1] = create_int(5);
  numbers->array[2] = create_int(8);
  numbers->array[3] = create_int(2);
  numbers->array[4] = create_int(13);
  numbers->array[5] = create_int(12);
  numbers->array[6] = create_int(1);

  printf("\nInsertion Sort\n");
  display_array(numbers, &display_number);
  insertion_sort(numbers, &is_number_lesser_than);
  display_array(numbers, &display_number);
}

int main(void)
{
  perform_selection_sort();
  perform_bubble_sort();
  perform_insertion_sort();
  return 0;
}