#include <stdio.h>
#include "string.h"

String *word1(int size_of_word)
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

String *word2(int size_of_word)
{
	String *str;
	str = malloc(sizeof(String));
	if(str == NULL) {
		return NULL;
	}

	if(size_of_word == 1) {
		str->array = malloc((size_of_word + 1)*sizeof(char));
		str->cap = size_of_word + 1;
	}
	else if(size_of_word > 1) {
		str->array = realloc((size_of_word + 1)*sizeof(char));
		str->cap = size_of_word + 1;
	}
	else {
		return NULL;
	}
	return str;
}

void free_word(String *arr)
{
	free(arr->array);
	arr->size = 0;
	arr->cap = 0;
	free(arr);
}

