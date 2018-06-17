#include "stdio.h"
#include "string.h"

String *word(int size_of_word)
{
	String *arr;
	arr = malloc(sizeof(String));
	if(arr == NULL) {
		return NULL;
	}

	if(size_of_word == 1) {
		arr->array = malloc((size_of_word + 1)*sizeof(char));
		arr->cap = size_of_word + 1;
	}
	else if(size_of_word > 1) {
		arr->array = realloc((size_of_word + 1)*sizeof(char));
		arr->cap = size_of_word + 1;
	}
	else {
		return NULL;
	}
	return arr;
}