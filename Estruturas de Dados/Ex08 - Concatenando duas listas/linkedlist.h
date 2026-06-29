#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

LinkedList *ll_create();

void ll_insert(LinkedList *lista, int valor);

void ll_insert_sorted(LinkedList *lista, int valor);

void ll_append(LinkedList *lista, int valor);

int ll_remove(LinkedList *lista, int valor);

void ll_remove_all(LinkedList *lista, int valor);

int ll_size(LinkedList *lista);

int ll_is_in(LinkedList *lista, int valor);

int ll_is_empty(LinkedList *lista);

int ll_is_sorted(LinkedList *lista);

LinkedList *ll_reversed(LinkedList *lista);

LinkedList *ll_concatenate(LinkedList *lista1, LinkedList *lista2);

void ll_free(LinkedList *lista);

void ll_print(LinkedList *lista);

LinkedList *ll_concatenated(LinkedList *lista1, LinkedList *lista2);

#endif