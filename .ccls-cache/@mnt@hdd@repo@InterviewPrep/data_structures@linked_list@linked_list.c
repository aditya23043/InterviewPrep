#include "linked_list.h"

void initialize(struct Node *node) {
    node = NULL;
}

void add(struct Node *node, int value) {

    struct Node *temp = node;

    // case: empty list
    if (temp = NULL) {
        node = malloc(sizeof(struct Node*));
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = malloc(sizeof(struct Node*));
        temp = temp->next;
    }
    temp->value = value;
    temp->next = NULL;
}

void print(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

void clean(struct Node *node) {
    struct Node *temp;
    while (node != NULL) {
        temp = node;
        node = temp->next;
        free(temp);
    }
}
