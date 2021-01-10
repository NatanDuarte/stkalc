#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define EMPTY 0

Stack *createStack(unsigned int capacity) {
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->cap = capacity;
    s->top = EMPTY;
    s->data = (int*) malloc(sizeof(int) * s->cap);
    return s;
}

int push(Stack *s, int newValue) {
    if (stackIsFull(s)) {
        return false;
    }
    s->data[s->top++] = newValue;
    return true;
}

int pop(Stack *s) {
    if (stackIsEmpty(s)) {
        return INT_MIN;
    }

    return s->data[--s->top];
}

int peek(Stack *s) {
    if (stackIsEmpty(s)) {
        return INT_MIN;
    }

    int topValue = s->top - 1;
    return s->data[topValue];
}

int stackIsFull(Stack *s) {
    return s->top >= s->cap;
}

int stackIsEmpty(Stack *s) {
    return s->top == EMPTY;
}

void destroyStack(Stack *s) {
    free(s->data);
    free(s);
}
