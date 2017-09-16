#pragma once

class Book{
private:
	int _id;
	char* _Name = NULL;
	char* _Author = NULL;
	char* _PublishingHouse = NULL;
	void MemoryAlloc(char *&,int);
	void MemoryClear(char *&);
public:
	int GetID();
	void SetID(int);
	char* GetName();
	void SetName(char*);
	char* GetAuthor();
	void SetAuthor(char*);
	char* GetPublishingHouse();
	void SetPublishingHouse(char*);
	void PrintBookInfo();
	Book();
	Book(Book&);
	Book(int,char*,char*,char*);
	Book &operator = (Book &obj);
	~Book();
};

void Book::MemoryClear(char *&arr) {
	if (arr != nullptr) {
			delete[] arr;
	}
}

void Book::MemoryAlloc(char *&arr,int size) {
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
	MemoryAlloc(_Name,strlen(str)+1);
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
	//this->MemoryAlloc(_Name, 1);
	//this->MemoryAlloc(_PublishingHouse, 1);
	//_Name = '\0';
	//_PublishingHouse = '\0';
	/*
	char Tmp[100];
	//cout << "Конструктор класса без параметров" << endl;
	cout << "Номер книги:";
	cin >> _id;
	cout << "Название книги:";
	cin >> Tmp;
	/////_Name.push_back(Tmp);
	cout << "Издательство:";
	cin >> Tmp;
	///_PublishingHouse.push_back(Tmp);
	*/
}

Book::Book(int id_p, char *Name_p, char* Author_p, char *PublishingHouse_p) {
	this->MemoryAlloc(_Name, strlen(Name_p) + 1);
	this->MemoryAlloc(_Author, strlen(Author_p) + 1);
	this->MemoryAlloc(_PublishingHouse, strlen(PublishingHouse_p) + 1);
	_id = id_p;
	strcpy(_Name, Name_p);
	strcpy(_Author, Author_p);
	strcpy(_PublishingHouse, PublishingHouse_p);
}

Book::Book(Book &obj) {
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