#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct List List;
typedef struct Node Node;

List* list_init();
size_t list_size(const List* list);
int list_empty(const List* list);
int list_pushback(List* list, int val);
int list_pushfront(List* list, int val);
int list_popback(List* list);
int list_popfront(List* list);
void list_print(const List* list);
int list_find(const List* list, int target);
int list_insert(List* list, int val, int pos);
int list_remove(List* list, int pos);
void list_foreach(const List* list, void (*callback)(int));
void list_clear(List* list);
void list_destroy(List* list);

#endif