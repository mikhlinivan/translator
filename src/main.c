#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include <locale.h>

int main(int argv,char *arcg[])
{
	setlocale(LC_ALL, "Rus");
	//arcg[0] ./translator
	//arcg[1] 
	//arcg[2] 
	//arcg[3] 
	FILE *in, *translator, *out;
	char curr_symb, prev_symb, curr_translator_symb;
	int i, size, lenght_of_translator, size_of_translator, checker, count, lenght_of_translated;
	String *word_readed;
	String *translator_readed;
	String *translation;
	word_readed = word1();
	translator_readed = word1();
	translation = word1();
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
	curr_symb = 'a';
	size = 1;
	i = 0;
	lenght_of_translator = 1;
	size_of_translator = 0;
	while (curr_symb != EOF) {
		prev_symb = curr_symb;
		curr_symb = getc(in);
		while (((curr_symb >= 'à') && (curr_symb <= 'ÿ')) || ((curr_symb >= 'À') && (curr_symb <= 'ß'))) { 
			size++;
			write_symb(curr_symb, size, i, word_readed);
			i++;
			curr_symb = getc(in);
		}
		if(((prev_symb >= 'à') && (prev_symb <= 'ÿ')) || ((prev_symb >= 'À') && (prev_symb <= 'ß'))) { 
			lenght_of_translator++;
			curr_translator_symb = getc(translator);
			while(curr_translator_symb != EOF) {
				while (((curr_translator_symb >= 'à') && (curr_translator_symb <= 'ÿ')) || ((curr_translator_symb >= 'À') && (curr_translator_symb <= 'ß'))) {
					write_symb(curr_translator_symb, lenght_of_translator, size_of_translator, translator_readed);
					lenght_of_translator++;
					size_of_translator++;
					curr_translator_symb = getc(translator);
				}
				checker = check(word_readed, translator_readed);
				if(checker == 0) { 
					fseek(translator , 2, SEEK_CUR);
					curr_translator_symb = getc(translator);
					count = 0;
					lenght_of_translated = 1;
					while(((curr_translator_symb >= 'a') && (curr_translator_symb <= 'z')) || ((curr_translator_symb >='A') && (curr_translator_symb <= 'Z'))) {
						lenght_of_translated++;
						write_symb(curr_translator_symb, lenght_of_translated, count, translation);
						curr_translator_symb = getc(translator);
						count++;
					}
					count = 0;
					while (translation->array[count] != '\0') {
						fprintf(out, "%c", translation->array[count]);
						count++;
					}
					fseek(translator, 0, SEEK_SET);
					goto next_point1;
				}
				curr_translator_symb = getc(translator);
			}
			if(checker == 1) {
				count = 0;
				while (word_readed->array[count] != '\0') {
					fprintf(out, "%c", word_readed->array[count]);
				}
			}
		}
		else if (prev_symb != EOF) {
			fprintf(out, "%c", prev_symb);
		}
		next_point1:
		after(word_readed);
		after(translator_readed);
		after(translation);
	}
	free_string(word_readed);
	free_string(translator_readed);
	free_string(translation);
	fclose(in);
	fclose(translator);
	fclose(out);
	return 0;
	}