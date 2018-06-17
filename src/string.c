#include <stdio.h>
#include "string.h"

String *word1()
{
	String *arr;
	arr = malloc(sizeof(String));
	if(arr == NULL) {
		return NULL;
	}
	else {
		arr->array = malloc(1*sizeof(char));
		arr->cap = 1;
	}
	return arr;
}

String *write(char symb, int size, int symb_num)
{
	arr->array = realloc(size*sizeof(char));
	arr->cap = size;
	arr->array[symb_num] = symb;
}

void free_word(String *arr)
{
	free(arr->array);
	arr->size = 0;
	arr->cap = 0;
	free(arr);
}

