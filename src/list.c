#include "../include/list.h"

struct Node{
    int data;
    struct Node* next;
};

// utility function -- to create a new node -- used by list insert functions
Node* node_create(int val){
    Node* node = malloc(sizeof(Node));

    // memory allocation fails
    if (!node)
        return NULL;

    node->data = val;
    node->next = NULL;
    return node;
}

// utility function -- to release the memory of a node -- used by list remove functions
void node_destroy(Node* node){
    free(node);
}

struct List{
    Node sentinel; // sentinel node to handle edge cases smoothly
    Node* tail; // tail pointer to O(1) push/pop at the back of the list
    size_t size; // number of nodes in the list
};

// initialising an empty list
List* list_init(){
    List* list = malloc(sizeof(List));

    // memory allocation fails
    if (!list)
        return NULL;

    list->sentinel.next = NULL;
    list->tail = &list->sentinel;
    list->size = 0;
    return list;
}

// returns number of nodes in the list
size_t list_size(const List* list){
    return list->size;
}

// returns 1 if list is empty, otherwise 0
int list_empty(const List* list){
    return list->size == 0;
}

// insertion at the end of the list
// returns 1 is insertion succeeds, otherwise 0
int list_pushback(List* list, int val){
    Node* node = node_create(val);

    // if memory for node is not allocated
    if (!node)
        return 0; // push failed -- node allocation failed

    list->tail->next = node;
    list->tail = node;
    list->size++;

    return 1; // push successful
}

// insertion at the beginning of the list
// returns 1 is insertion succeeds, otherwise 0
int list_pushfront(List* list, int val){
    Node* node = node_create(val);

    // if memory for node is not allocated
    if (!node)
        return 0; // push failed -- node allocation failed

    node->next = list->sentinel.next;
    list->sentinel.next = node;

    if (list_empty(list))
        list->tail = node;

    list->size++;

    return 1; // push successful
}

// insertion at a specific position
// returns 1 if insertion succeeds, otherwise 0
int list_insert(List* list, int val, int pos){
    if (pos < 0 || (size_t)pos > list->size)
        return 0; // insert failed -- invalid position
    
    Node* node = node_create(val);

    // if memory of node is not allocated
    if (!node)
        return 0; // insert failed -- node allocation failed

    int c = 0;

    Node* prev = &list->sentinel;

    while (c < pos){
        prev = prev->next;
        c++;
    }

    node->next = prev->next;
    prev->next = node;

    // if the node is inserted at the end of the list
    if (node->next == NULL)
        list->tail = node;

    list->size++;

    return 1; // insert successful
}

// removal of node at the end of the list
// returns 1 if removal succeeds, otherwise 0
int list_popback(List* list){
    if (list_empty(list))
        return 0; //pop unsuccessful -- list empty
    
    Node* prev = &list->sentinel;

    while (prev->next != list->tail)
        prev = prev->next;

    Node* removed = list->tail;
    node_destroy(removed);
    list->size--;

    prev->next = NULL;
    list->tail = prev;

    return 1; //pop successful -- data exists
}

// removal of node at the beginning of the list
// returns 1 if removal succeeds, otherwise 0
int list_popfront(List* list){

    if (list_empty(list))
        return 0; //pop unsuccessful -- list empty
    
    Node* removed = list->sentinel.next;
    
    list->sentinel.next = removed->next;
    
    if (removed == list->tail)
        list->tail = &list->sentinel;

    node_destroy(removed);
    list->size--;
    return 1; //pop successful -- data exists
}

// removal of node at a specific position
// returns 1 if removal succeeds, otherwise 0
int list_remove(List* list, int pos){
    if (pos < 0 || (size_t)pos >= list->size)
        return 0; // remove failed -- invalid position
    
    Node* prev = &list->sentinel;

    int c = 0;

    while (c < pos){
        prev = prev->next;
        c++;
    }

    Node* removed = prev->next;
    if (removed == list->tail)
        list->tail = prev;

    prev->next = removed->next;
    node_destroy(removed);

    list->size--;

    return 1; // remove successful
}

// searches the list for a given target value
// if found returns its position (index), otherwise returns -1
int list_find(const List* list, int target){
    
    int pos = 0;

    Node* node = list->sentinel.next;
    while (node) {
        if (node->data == target)
            return pos; // found
        pos++;
        node = node->next;
    }

    return -1; // not found
}


// to apply a function of type void callback(int) to each node->data of the list
void list_foreach(const List* list, void (*callback)(int)){

    if (callback == NULL)
        return;

    Node* node = list->sentinel.next;
    while (node) {
        callback(node->data);
        node = node->next;
    }
}

void list_print(const List* list){

    Node* node = list->sentinel.next;

    printf("Start -> ");
    while (node){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("X\n");
}

// removal of all nodes of the list
// keeps the structure of the list
void list_clear(List* list){

    Node* node = list->sentinel.next;

    while (node){
        Node* next = node->next;
        node_destroy(node);
        node = next;
    }

    list->sentinel.next = NULL;
    list->tail = &list->sentinel;
    list->size = 0;
}

// to destroy the list and free up the memory
void list_destroy(List* list){
    list_clear(list);
    free(list);
}