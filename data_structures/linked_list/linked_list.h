#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void initialize(struct Node *node);
void add(struct Node *node, int value);
void print(struct Node *node);
void clean(struct Node *node);
