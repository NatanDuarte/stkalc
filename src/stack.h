#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack {
    unsigned int cap;
    unsigned int top;
    int *data;
} Stack;

Stack *createStack(unsigned int capacity);

int push(Stack *s, int newValue);
int pop(Stack *s);
int peek(Stack *s);

int stackIsFull(Stack *s);
int stackIsEmpty(Stack *s);

void destroyStack(Stack *s);

#endif
