#include <stdio.h>
#include "string.h"
#include <locale.h>

String *word1()
{
	setlocale(LC_ALL, "Rus");
	String *arr;
	arr = malloc(sizeof(String));
	if(arr == NULL) {
		return NULL;
	}
	else {
		arr->array = malloc(2*sizeof(char));
		arr->cap = 2;
		arr->size = 0;
	}
	return arr;
}

write_symb(char symb, int size, int symb_num, String *arr)
{
	setlocale(LC_ALL, "Rus");
	realloc(arr->array, size*sizeof(char));
	arr->cap = size;
	arr->size++;
	arr->array[symb_num] = symb;
	arr->array[symb_num + 1] = '\0';
	return arr;
}

void free_string(String *arr)
{
	setlocale(LC_ALL, "Rus");
	free(arr->array);
	arr->size = 0;
	arr->cap = 0;
	free(arr);
}

int check(String *translated, String *translator)
{
	setlocale(LC_ALL, "Rus");
	int i, flg;
	i = 0;
	flg = 1;
	while (translated->array[i] != '\0') {
		if(translated->array[i] == translator->array[i]) {
			flg = 0;
			i++;
		}
		else {
			flg = 1;
			return flg;
		}
	}
	return flg;
}

void after(String *arr)
{
	int i;
	while (arr->array[i] != '\0') {
		arr->array[i] = 0;
		i++;
	}
	realloc(arr->array, 2*sizeof(char));
	arr->cap = 2;
	arr->size = 0;
}