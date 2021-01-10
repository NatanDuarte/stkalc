#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int intInput(char * prompt) {
    int input = 0;
    printf("%s", prompt);
    fscanf(stdin, "%d", &input);
    return input;
}

unsigned int uintInput(char * prompt) {
    unsigned int input = 0;
    printf("%s", prompt);
    fscanf(stdin, "%u", &input);
    return input;
}

float floatInput(char * prompt) {
    float input = 0.0000000;
    printf("%s", prompt);
    fscanf(stdin, "%f", &input);
    return input;
}

double longInput(char * prompt) {
    double input = 0.00000000000000;
    printf("%s", prompt);
    fscanf(stdin, "%lf", &input);
    return input;
}

char charInput(char * prompt) {
    char input = ' ';
    printf("%s", prompt);
    fscanf(stdin, "%c", &input);

    return input;
}

unsigned char ucharInput(char * prompt) {
    unsigned char input = ' ';
    printf("%s", prompt);
    fscanf(stdin, "%c", &input);

    return input;
}

char * readLine(char * prompt) {
    printf("%s", prompt);

    setbuf(stdin, 0);
    char * input = (char *) malloc(sizeof(size_t));
    fscanf(stdin, "%[^\n]s", input);

    input = realloc(
        input,
        sizeof(char) * (strlen(input) + 1)
    );

    return input;
}

char * read(char * prompt) {
    printf("%s", prompt);

    setbuf(stdin, 0);
    char * input = (char *) malloc(sizeof(size_t));
    fscanf(stdin, "%s", input);

    input = realloc(
        input,
        sizeof(char) * (strlen(input) + 1)
    );

    return input;
}
