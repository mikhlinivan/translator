#include <stdio.h>

typedef struct {
	int size;
	int cap;
	char *array;
} String;

String *word1(int size_of_word);
String *write(char symb);
void free(String *arr)
