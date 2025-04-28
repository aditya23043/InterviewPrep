#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int *array;
    int index;
} Array;

void arr_init(Array *temp);
int arr_is_empty(Array arr);
int arr_size(Array arr);
void arr_add(Array *arr, int num);
int arr_set(Array *arr, int num, int index);
int arr_set(Array *arr, int num, int index);
int arr_delete(Array *arr);
int arr_delete_element(Array *arr, int num);
int arr_contains(Array arr, int num);
int arr_print(Array arr);
void arr_cleanup(Array *arr);
void sample_code();

#endif
