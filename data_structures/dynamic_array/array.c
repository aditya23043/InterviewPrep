#include "array.h"

/* initialize array parameters */
void arr_init(Array *temp) { temp->index = -1; }

/* Check if the array [arr] is empty */
int arr_is_empty(Array arr) {
    if (arr.index == -1) {
        return 1;
    }
    return 0;
}

/* Returns the size of the array */
int arr_size(Array arr) {
    return arr.index+1;
}

/* Add [num] to the end of the array [arr] */
void arr_add(Array *arr, int num) {
    if (arr->index > -1) {
        int temp[arr->index + 1];
        for (int i = 0; i <= arr->index; i++) {
            temp[i] = arr->array[i];
        }
        free(arr->array);
        arr->index++;
        arr->array = malloc(sizeof(int) * (arr->index + 1));
        for (int i = 0; i < arr->index; i++) {
            arr->array[i] = temp[i];
        }
        arr->array[arr->index] = num;
    } else {
        arr->array = malloc(sizeof(int));
        arr->index++;
        arr->array[0] = num;
    }
}

/* Changes the value at [index] to [num] */
/* returns 0 on success and -1 on error */
int arr_set(Array *arr, int num, int index) {
    if (index > arr->index || index < 0) {
        return -1;
    }
    arr->array[index] = num;
    return 0;
}

/* delete the last element of the array [arr] */
/* Returns 0 on success or -1 on error */
int arr_delete(Array *arr) {
    if (arr->index > 0) {
        int temp[arr->index];
        for (int i = 0; i < arr->index; i++) {
            temp[i] = arr->array[i];
        }
        free(arr->array);
        arr->array = malloc(sizeof(int) * arr->index);
        for (int i = 0; i < arr->index; i++) {
            arr->array[i] = temp[i];
        }
        arr->index--;
    } else if (arr->index == 0) {
        arr->index--;
        free(arr->array);
    } else if (arr->index == -1) {
        /* printf("[Cannot Delete from Empty Array]\n"); */
        return -1;
    }
    return 0;
}

/* delete the element [num] from the array [arr] */
/* Returns 0 on success or -1 on error */
int arr_delete_element(Array *arr, int num) {
    int index = -1;
    for (int i = 0; i <= arr->index; i++) {
        if (arr->array[i] == num) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        /* printf("[Cannot find element to delete: %d]\n", num); */
        return -1;
    } else {
        int temp[arr->index];
        for (int i = 0; i < index; i++) {
            temp[i] = arr->array[i];
        }
        for (int i = index + 1; i <= arr->index; i++) {
            temp[i - 1] = arr->array[i];
        }
        free(arr->array);
        arr->array = malloc(sizeof(int) * (arr->index));
        for (int i = 0; i < arr->index; i++) {
            arr->array[i] = temp[i];
        }
        arr->index--;
    }
    return 0;
}

/* Returns index of the element or -1 if element not found */
int arr_contains(Array arr, int num) {
    int index = -1;
    for (int i = 0; i <= arr.index; i++) {
        if (arr.array[i] == num) {
            index = i;
            break;
        }
    }
    return index;
}

/* print the elements of the array [arr] */
/* Returns 0 on success or -1 on error */
int arr_print(Array arr) {
    if (arr.index > -1) {
        /* printf("%p: [", arr); */
        printf("[");
        for (int i = 0; i <= arr.index; i++) {
            printf("%d", arr.array[i]);
            if (i != arr.index)
                printf(",");
        }
        printf("]\n");
    } else {
        /* printf("[Empty Array]\n"); */
        return -1;
    }

    return 0;
}

/* Free all the allocated blocks in the array [arr] */
void arr_cleanup(Array *arr) {
    if (arr->index > -1) {
        free(arr->array);
    }
}
