#include "array.h"

int main(void) {

    Array arr;
    int ret;

    arr_init(&arr);

    printf("[EMPTY] %d\n", arr_is_empty(arr));

    arr_add(&arr, 1);  // 1
    arr_add(&arr, 8);  // 1, 8
    arr_add(&arr, 6);  // 1, 8, 6
    arr_add(&arr, 12); // 1, 8, 6, 12
    arr_add(&arr, 4);  // 1, 8, 6, 12, 4

    arr_set(&arr, 82, 3); // 1,8,6,82,4
    arr_print(arr);

    ret = arr_contains(arr, 12);
    printf("[CONTAINS] Return Value: %d\n", ret); // 3

    printf("[EMPTY] %d\n", arr_is_empty(arr));

    arr_delete_element(&arr, 8); // 1, 6, 82, 4
    ret = arr_delete_element(&arr, 72);
    printf("[DELETE ELEMENT] Return Value: %d\n", ret); // -1 because element not found

    arr_delete(&arr); // 1, 6, 82

    arr_print(arr);

    arr_delete(&arr); // 1, 6

    arr_delete(&arr);       // 1
    ret = arr_delete(&arr); // 0 (success)
    printf("[DELETE] Return Value: %d\n", ret);

    arr_delete(&arr);       // [empty]
    ret = arr_delete(&arr); // -1 (cannot delete any more from empty array)
    printf("[DELETE] Return Value: %d\n", ret);

    ret = arr_print(arr); // -1 (empty arr)
    printf("[PRINT] Return Value: %d\n", ret);

    arr_cleanup(&arr);

    return 0;
}
