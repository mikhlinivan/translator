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
		arr->array = malloc(2*sizeof(char));
		arr->cap = 2;
	}
	return arr;
}

void free_word(String *arr)
{
	free(arr->array);
	arr->size = 0;
	arr->cap = 0;
	free(arr);
}

