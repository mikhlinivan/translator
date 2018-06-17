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
	int i, size, lenght_of_translator, size_of_translator, checker;
	String *word_readed;
	String *translator_readed;
	word_readed = word1();
	translator_readed = word1();
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
	curr_symb = getc(in);
	size = 0;
	i = 0;
	lenght_of_translator = 0;
	size_of_translator = 0;
	while (curr_symb != EOF) {
		prev_symb = curr_symb;
		while (((curr_symb >= 'а') && (curr_symb <= 'я')) || ((curr_symb >= 'А') && (curr_symb <= 'Я'))) { //пишем первую строку(переводимое) запись начнется при попадании первой же буквы в функцию, если знак перпинания смотреть ниже
			size++;
			word_readed = write(curr_symb, size, i);
			i++;
			curr_symb = getc(in);
		}
		if(((prev_symb >= 'а') && (prev_symb <= 'я')) || ((prev_symb >= 'А') && (prev_symb <= 'Я'))) { //пишем вторую строку(слово из словарика) запись начнется при первом же русском символе в словарике, если знак препинания: игнорировать до русской буквы
			lenght_of_translator++
			curr_translator_symb = getc(translator);
			while(curr_translator_symb != EOF) {
				while (((curr_translator_symb >= 'а') && (curr_translator_symb <= 'я')) || ((curr_translator_symb >= 'А') && (curr_translator_symb <= 'Я'))) {
					translator_readed = write(curr_translator_symb, lenght_of_translator, size_of_translator);
					lenght_of_translator++;
					size_of_translator++;
				}
				checker = check(word_readed, translator_readed);
				if(checker == 0) {
					while 
				//сравниваем
			//если не совпало пишем следущее слово из словаря и так до конца файла или совпадения
		//при совпадении пишем в выхождной файл перевод используя алгоритм который придумаю
		//если совпадений нет то пишем то что было
		//если знак препинания пишем его
		//возращаемся в начало словаря
	}