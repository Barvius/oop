#include <iostream>

#include "Book.h"

using namespace std;


int main() {
	setlocale(0, "rus");
	Book book1;
	book1.PrintBookInfo();
	Book book2(book1);
	cout << "Название:";
	char Tmp[100];
	cin >> Tmp;
	book2.SetName(Tmp);
	book2.PrintBookInfo();
	Book book3(123,"моя книга","dfsd","tghtyj");
	book3.PrintBookInfo();
	system("pause");
	return 0;
}