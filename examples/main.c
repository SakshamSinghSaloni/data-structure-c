#include <stdio.h>
#include "../include/list.h"

void print_square(int x){
    printf("%d ", x * x);
}

int main(){
    List* myList = list_init();

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < size; i++)
    list_pushback(myList, arr[i]);

    list_foreach(myList, print_square);
    printf("\n");
    
    list_print(myList);
    printf("%d\n", list_find(myList, 5));
    
    for (int i = 0; i < 4; i++)
    list_popfront(myList);
    
    list_print(myList);

    printf("%d\n", list_find(myList, 5));

    list_clear(myList);
    list_print(myList);

    list_destroy(myList);
}