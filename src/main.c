#include <stdio.h>
#include "word.h"
#include "translator.h"
#include <locale.h>

int main(int argv,char *arcg[])
{
	setlocale(LC_ALL, "Rus");
	//arcg[0] ./translator
	//arcg[1] текст пользователя
	//arcg[2] файл переводчика
	//arcg[3] переведенный файл
	FILE *in, *translator, *out;
	char curr_symb, prev_symb, curr_translator_symb;
	int i;
	String *word_readed;
	string *translator_readed;
	in = fopen(arcg[1], "r");
	if(in == NULL) {
		printf("text dont exist\n");
		return 0;
	}
	translator = fopen(arcg[2], "r");
	if(translator == NULL) {
		printf("translator dont exist");
		return 0;
	}
	out = fopen(arcg[3], "w");
	int word_lenght = 0;
	while (curr_symb != EOF) {
		
	}