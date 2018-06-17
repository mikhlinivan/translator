#include "stdio.h"

typedef struct {
	int size;
	int cap;
	char *array;
} String;

String *word(int size_of_word);
