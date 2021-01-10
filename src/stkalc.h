#ifndef __STKALC_H__
#define __STKALC_H__

#include "inputs.h"
#include "stack.h"
#include <stdbool.h>

enum OPCODES {
    ADD, SUB, MUL, DIV, PUSH, POP, CLEAR, H, Q,
    total_opcodes
};

void printStack(Stack * s);
bool compare(char * input, char * token);
void printCommandList();
void clearScreen();
int  parser(char * input);
void proccess(Stack * s, int opcode);
void add(Stack * s);
void sub(Stack * s);
void mul(Stack * s);
void divide(Stack * s);

#endif