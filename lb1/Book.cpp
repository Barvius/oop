#include "Book.h"

using namespace std;

void Book::_MemoryAlloc(char *&arr, int size, char* str) {
	if (arr != nullptr) {
		delete[] arr;
	}
	arr = new char[size];
	strcpy(arr, str);
}

int Book::GetID() {
	return _id;
}

void Book::SetID(int num) {
	_id = num;
}

char* Book::GetName() {
	return _Name;
}

void Book::SetName(char* str) {
	_MemoryAlloc(_Name, strlen(str) + 1,str);
}

char* Book::GetAuthor() {
	return _Author;
}

void Book::SetAuthor(char* str) {
	_MemoryAlloc(_Author, strlen(str) + 1, str);
}

char* Book::GetPublishingHouse() {
	return _PublishingHouse;
}

void Book::SetPublishingHouse(char* str) {
	_MemoryAlloc(_PublishingHouse, strlen(str) + 1, str);
}

void Book::PrintBookInfo() {
	cout << "# id" << setw(11) << ":" << _id << endl;
	cout << "# Название" << setw(5) << ":" << _Name << endl;
	cout << "# Автор" << setw(8) << ":" << _Author << endl;
	cout << "# Издательство" << setw(1) << ":" << _PublishingHouse << endl;
}

Book::Book() {
	cout << "конструктор без параметров" << endl;
	char Tmp[100];
	cout << "Номер книги" << setw(4) << ":";
	cin >> _id;
	cout << "Название книги" << ":";
	cin >> Tmp;
	SetName(Tmp);
	cout << "Автор" << setw(10) << ":";
	cin >> Tmp;
	SetAuthor(Tmp);
	cout << "Издательство" << setw(3) << ":";
	cin >> Tmp;
	SetPublishingHouse(Tmp);
}

Book::Book(int id_p, char *Name_p, char *Author_p, char *PublishingHouse_p) {
	cout << "конструктор с параметром" << endl;
	SetID(id_p);
	SetName(Name_p);
	SetAuthor(Author_p);
	SetPublishingHouse(PublishingHouse_p);
}

Book::Book(Book &obj) {
	cout << "конструктор копии" << endl;
	SetID(obj._id);
	SetName(obj._Name);
	SetAuthor(obj._Author);
	SetPublishingHouse(obj._PublishingHouse);
}

Book &Book::operator = (Book &obj) {
	SetID(obj._id);
	SetName(obj._Name);
	SetAuthor(obj._Author);
	SetPublishingHouse(obj._PublishingHouse);
	return Book(*this);
}

Book::~Book() {
	delete[] _Name;
	delete[] _Author;
	delete[] _PublishingHouse;
}