#include "Header.h"
void give_names(string&, string&); //надання імен файлам
void create_txt(string);           //створення нового файлуб введення тексту
void print_txt(string);            //друкування файлу
void changing(string, string);     //створення нового файлу зі зміненим текстом
int main() {
	string name, name2;           //імена файлів
	give_names(name, name2);
	create_txt(name);
	cout << "Your text is: ";
	print_txt(name);
	changing(name, name2);
	cout << "New text is: ";
	print_txt(name2);
	return 0;
}