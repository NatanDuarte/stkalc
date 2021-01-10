#ifndef __INPUTS_H__
#define __INPUTS_H__

int intInput(char * prompt);
unsigned int uintInput(char * prompt);

float floatInput(char * prompt);
double longInput(char * prompt);

char charInput(char * prompt);
unsigned char ucharInput(char * prompt);

char * readLine(char * prompt);
char * read(char * prompt);

#endif