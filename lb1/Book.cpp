#include "Book.h"

using namespace std;

void Book::MemoryClear(char *&arr) {
	if (arr != nullptr) {
		delete[] arr;
	}
}

void Book::MemoryAlloc(char *&arr, int size) {
	if (arr != nullptr) {
		delete[] arr;
	}
	arr = new char[size];
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
	MemoryAlloc(_Name, strlen(str) + 1);
	strcpy(_Name, str);
}

char* Book::GetAuthor() {
	return _Author;
}

void Book::SetAuthor(char* str) {
	MemoryAlloc(_Author, strlen(str) + 1);
	strcpy(_Author, str);
}

char* Book::GetPublishingHouse() {
	return _PublishingHouse;
}

void Book::SetPublishingHouse(char* str) {
	MemoryAlloc(_PublishingHouse, strlen(str) + 1);
	strcpy(_PublishingHouse, str);
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
	this->MemoryAlloc(_Name, strlen(Tmp) + 1);
	strcpy(_Name, Tmp);
	cout << "Автор" << setw(10) << ":";
	cin >> Tmp;
	this->MemoryAlloc(_Author, strlen(Tmp) + 1);
	strcpy(_Author, Tmp);
	cout << "Издательство" << setw(3) << ":";
	cin >> Tmp;
	this->MemoryAlloc(_PublishingHouse, strlen(Tmp) + 1);
	strcpy(_PublishingHouse, Tmp);
}

Book::Book(int id_p, char *Name_p, char* Author_p, char *PublishingHouse_p) {
	cout << "конструктор с параметром" << endl;
	this->MemoryAlloc(_Name, strlen(Name_p) + 1);
	this->MemoryAlloc(_Author, strlen(Author_p) + 1);
	this->MemoryAlloc(_PublishingHouse, strlen(PublishingHouse_p) + 1);
	_id = id_p;
	strcpy(_Name, Name_p);
	strcpy(_Author, Author_p);
	strcpy(_PublishingHouse, PublishingHouse_p);
}

Book::Book(Book &obj) {
	cout << "конструктор копии" << endl;
	this->MemoryAlloc(_Name, strlen(obj._Name) + 1);
	this->MemoryAlloc(_Author, strlen(obj._Author) + 1);
	this->MemoryAlloc(_PublishingHouse, strlen(obj._PublishingHouse) + 1);
	_id = obj._id;
	strcpy(_Name, obj._Name);
	strcpy(_Author, obj._Author);
	strcpy(_PublishingHouse, obj._PublishingHouse);
}

Book &Book::operator = (Book &obj) {
	this->MemoryAlloc(_Name, strlen(obj._Name) + 1);
	this->MemoryAlloc(_Author, strlen(obj._Author) + 1);
	this->MemoryAlloc(_PublishingHouse, strlen(obj._PublishingHouse) + 1);
	_id = obj._id;
	strcpy(_Name, obj._Name);
	strcpy(_Author, obj._Author);
	strcpy(_PublishingHouse, obj._PublishingHouse);
	return Book(*this);
}

Book::~Book() {
	this->MemoryClear(_Name);
	this->MemoryClear(_PublishingHouse);
}