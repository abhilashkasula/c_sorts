#include <stdio.h>
#include <stdlib.h>

/*
The consumer of this Linked List library is expected to take care of allocating & freeing elements.
The Linked List maintains the element references in a sequence and provides convenient operations on them.
*/

#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

typedef enum
{
  Failure,
  Success
} Status;

typedef void *Element;

typedef struct node
{
  Element element;
  struct node *next;
  struct node *prev;
} Node;

typedef Node *Node_ptr;

typedef struct linklist
{
  Node *first;
  Node *last;
  int length;
} LinkedList;

typedef struct
{
  Node *prev;
  Node *curr;
} Prev_curr_pair;

typedef LinkedList *List_ptr;
typedef void (*Displayer)(Element);

List_ptr create_list(void);
Node_ptr create_node(Element);

Status add_to_list(List_ptr, Element);
void display_list(List_ptr, Displayer);
#endif
