#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void give_names(string& n1, string& n2) {
	cout << "Enter the name of file: ";
	cin >> n1;
	n1 += ".txt";
	cout << "Enter the name of new file: ";
	cin >> n2;
	n2 += ".txt";
}
void create_txt(string n) {
	string txt;
	ofstream outFile(n);
	cout << "Enter your text here: ";
	do {                                //зчитування тексту у файл до закінчення (Ctrl+z)
		getline(cin, txt);
		outFile << txt << endl;
	} while (cin);
	outFile.close();
}
void print_txt(string n) {
	ifstream inF(n);
	string s;
	do {                                //зчитування тексту з файлу
		getline(inF, s);
		cout << s << endl;
	} while (inF);
	inF.close();
}
void changing(string n, string m) {
	ifstream inF(n);
	ofstream outF(m);
	string s;
	int empty;          //місце останнього пробілу
	int if_space_end;   //якщо в кінці рядка пробіл
	char letter;        //літера, що вставлятиметься на початок
	do {
		getline(inF, s);
		empty = s.rfind(" ");  //пошук останнього пробілу
		if (empty == string::npos)  //умова: єдине слово
			letter = s[0];
		else if (empty == s.length() - 1) {          //умова: пробіл в кінці
			if_space_end = s.find_last_not_of(" ");  //остання літера
			s.erase(if_space_end + 1);               //видалення пробілів в кінці 
			empty = s.rfind(" ");
			letter = s[empty + 1];
		}
		else
			letter = s[empty + 1];
		outF << letter << s << endl;
	} while (inF);
	inF.close();
	outF.close();
}
