#include "stack.h"
#include "inputs.h"
#include "stkalc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printStack(Stack * s) {
    int i = 0;
    printf("\n memory: %d/%d | (bottom) [ ", s->top, s->cap);
    for (i = 0; i < s->top; i++) {
        printf(" %d ", s->data[i]);
    }
    printf(" ] (top) \n");
}

int parser(char * input) {
    int i = 0;
    char * tokens[total_opcodes] = {
        "add", "sub", "mul", "div",
        "push", "pop", "clear", "h", "q"
    };

    for (i = 0; i < total_opcodes; i++) {
        if (compare(input, tokens[i]) == true) {
            return ADD + i;
        }
    }
    return total_opcodes;
}

bool compare(char * input, char * token) {
    return (
        strcmp(input, token) == 0
    );
}

void printCommandList() {
    clearScreen();
    printf("------------------------------------------------\n");
    printf(" COMMAND LIST\n");
    printf(" command    : discription\n");
    printf("------------------------------------------------\n");
    printf(" add        : sum 2 top numbers                \n");
    printf(" sub        : sub 2 top numbers (order matters)\n");
    printf(" mul        : mul 2 top values                 \n");
    printf(" div        : mul 2 top values  (order matters)\n");
    printf(" push (arg) : add a value to top               \n");
    printf(" pop        : rem a value from top             \n");
    printf(" clear      : clear screen                     \n");
    printf(" h          : print command list               \n");
    printf(" q          : exit application                 \n");
    printf("------------------------------------------------\n");
}

void clearScreen() {
    if (__linux__) {
        system("clear");
    } else {
        system("cls");
    }
}



void add(Stack * s) {
    if (s->top < 2) {
        printf("WRN: need at least two values in stack to operate\n");
        return;
    }

    int x = pop(s);
    int y = pop(s);

    push(s, (
        x + y
    ));
}

void sub(Stack * s) {
    if (s->top < 2) {
        printf("WRN: need at least two values in stack to operate\n");
        return;
    }

    int y = pop(s);
    int x = pop(s);

    push(s, (
        x - y
    ));
}

void divide(Stack * s) {
    if (s->top < 2) {
        printf("WRN: need at least two values in stack to operate\n");
        return;
    }

    int x = pop(s);
    int y = pop(s);

    if (x == 0) {
        printf("WRN: imposible operation\n");
        return;
    }

    push(s, (
        x / y
    ));
}

void mul(Stack * s) {
    if (s->top < 2) {
        printf("WRN: need at least two values in stack to operate\n");
        return;
    }

    int x = pop(s);
    int y = pop(s);

    push(s, (
        x * y
    ));
}



void proccess(Stack * s, int opcode) {
    switch (opcode) {
    case H:
        printCommandList();
        break;

    case CLEAR:
        clearScreen();
        break;

    case ADD:
        add(s);
        break;

    case SUB:
        sub(s);
        break;

    case MUL:
        mul(s);
        break;

    case DIV:
        divide(s);
        break;

    case PUSH: {
        int input = intInput("\t");
        push(s, input);
        break;
    }

    case POP:
        if (stackIsEmpty(s)) {
            printf("\n: The stack is empty.\n");
            break;
        }

        printf("\n: %d\n", pop(s));
        break;

    default:
        printf("ERR: Token undefined.\n");
        break;
    }
}
