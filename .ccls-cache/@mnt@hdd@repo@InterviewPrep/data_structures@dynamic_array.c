#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
  int *array;
  int index;
} Array;

int is_empty(Array arr) {
  if (arr.index == -1) {
    return 1;
  }
  return 0;
}

void add(Array *arr, int new) {
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
    arr->array[arr->index] = new;
  } else {
    arr->array = malloc(sizeof(int));
    arr->index++;
    arr->array[0] = new;
  }
}

void print(Array arr) {
  if (arr.index > -1) {
	printf("%p: [", arr);
    for (int i = 0; i <= arr.index; i++) {
      printf("%d", arr.array[i]);
	  if(i != arr.index)
		printf(",");
    }
    printf("]\n");
  } else {
    printf("[Empty Array]\n");
  }
}

void delete(Array *arr) {
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
  } else if(arr->index == 0) {
    arr->index--;
    free(arr->array);
  } else if (arr->index == -1) {
    printf("[Cannot Delete from Empty Array]\n");
  }
}

void delete_element(Array *arr, int num) {
  int index = -1;
  for (int i = 0; i <= arr->index; i++) {
    if (arr->array[i] == num) {
	  index = i;
	  break;
	}
  }
  if (index == -1) {
    printf("[Cannot find element to delete: %d]\n", num);
  } else {
    int temp[arr->index];
    for (int i = 0; i < index; i++) {
      temp[i] = arr->array[i];
	}
	for (int i = index + 1; i <= arr->index; i++) {
	  temp[i-1] = arr->array[i];
	}
	free(arr->array);
	arr->array = malloc(sizeof(int)*(arr->index));
	for (int i = 0; i < arr->index; i++) {
	  arr->array[i] = temp[i];
	}
	arr->index--;
  }
}

void cleanup(Array *arr) {
  if (arr->index > -1) {
    free(arr->array);
  }
}

void init(Array *temp) { temp->index = -1; }

int main(int argc, char **argv) {

  Array arr;

  init(&arr);
  add(&arr, 1);
  add(&arr, 8);
  add(&arr, 6);
  add(&arr, 12);
  add(&arr, 4);
  delete_element(&arr, 8);
  delete(&arr);
  print(arr);
  cleanup(&arr);

  return 0;
}
