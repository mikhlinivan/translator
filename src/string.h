#include <stdio.h>
#include "stdlib.h"
#include <locale.h>

typedef struct {
	int size;
	int cap;
	char *array;
} String;

String *word1();
void write_symb(char symb, int size, int symb_num, String *arr);
int check(String *translated, String *translator);
void free_string(String *arr);
void after(String *arr);