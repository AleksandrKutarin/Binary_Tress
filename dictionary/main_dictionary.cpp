#include <iostream>
#include <string>
#include"dict_header.h"

using namespace std;

int main()
{
	setlocale(0, "rus");
	
	hash_table<string> ht(15);
	
	vector<string> v1{
		"Самолёт",
		"Ложка",
		"Кастрюля",
		"Шаурма",
		"Пельмень"	
	};

	vector<string> v2{
		"Стол",
		"Ложка",
		"Сковородка",
		"Шаурма",
		"Кола"
	};

	for (auto elem : v1) {
		ht.insert(elem, "таблица номер 1");
	}
	ht.print();
	cout << "====================" << endl;
	for (auto elem : v2) {
		if (ht.find(elem) == -1) {
			ht.insert(elem, "таблица номер 2");
		}
	}
	ht.print();
	

	return 0;
}