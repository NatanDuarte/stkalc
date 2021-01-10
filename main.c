#include "src/stack.h"
#include "src/inputs.h"
#include "src/stkalc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 8

void welcome(void);

int main() {
    Stack * stack = createStack(STACK_SIZE);
    char * quitToken = "q";

    clearScreen();
    welcome();
    for (;;) {
        printStack(stack);

        char * input = read("> ");

        if (compare(input, quitToken)) {
            break;
        }

        int opcode = parser(input);
        proccess(stack, opcode);
    }

    destroyStack(stack);
    return 0;
}

void welcome() {
    printf("------------------------------------------------\n");
    printf("  STKalc \n\n");
    printf("  A \"stack-based\" Calculator.\n");
    printf("------------------------------------------------\n");
    printf("  enter \"h\" for Help. \"q\" to quit.\n");
    printf("------------------------------------------------\n");
}
