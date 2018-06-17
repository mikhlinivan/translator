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

String *write_symb(char symb, int size, int symb_num)
{
	arr->array = realloc(size*sizeof(char));
	arr->cap = size;
	arr->size++;
	arr->array[symb_num] = symb;
	arr->array[symb_num + 1] = '\0';
}

void free_word(String *arr)
{
	free(arr->array);
	arr->size = 0;
	arr->cap = 0;
	free(arr);
}

int check(*String translated, *String translator)
{
	int i, flg;
	i = 0;
	flg = 1;
	if(translated->size == translator->size) {
		while (transleted->array[i] != '\0') {
			if(transleted->array[i] == translator->array[i]) {
				flg = 0;
				i++;
			}
			else {
				flg = 1;
				return flg;
			}
		}
	}
	return flg;
}

String *get_eng (FILE translator, String *eng_word)
{
	int i, lenght;
	char curr_symb;
	for(i = 0; i < 4; i++) {
		curr_symb = getc(translator);
	}
	i = 0;
	lenght = 1;
	while (((curr_symb >= 'a') && (curr_symb <= 'z')) || ((curr_symb >='A') && (curr_symb <= 'b'))) {
		eng_word = write_symb(curr_symb, lenght, i);
		curr_symb = getc(translator);
	}
	return eng_word;
}