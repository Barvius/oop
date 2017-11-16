#include "Book.h"

using namespace std;

char* Book::GetAuthor() {
	return _Author;
}

void Book::SetAuthor(char* str) {
	_MemoryAlloc(_Author,str);
}

char* Book::GetPublishingHouse() {
	return _PublishingHouse;
}

void Book::SetPublishingHouse(char* str) {
	_MemoryAlloc(_PublishingHouse, str);
}

void Book::Info() {
	cout << "# id" << setw(11) << ":" << GetID() << endl;
	cout << "# Название" << setw(5) << ":" << GetName() << endl;
	cout << "# Автор" << setw(8) << ":" << _Author << endl;
	cout << "# Издательство" << setw(1) << ":" << _PublishingHouse << endl;
}

Book::Book(){

}

Book::Book(Book &obj):Literature(obj.GetID(), obj.GetName()) {
	SetAuthor(obj._Author);
	SetPublishingHouse(obj._PublishingHouse);
}

Book::Book(int id, char *Name, char *Author, char *PublishingHouse) : Literature(id, Name) {
	SetAuthor(Author);
	SetPublishingHouse(PublishingHouse);
}

Book::~Book(){
	delete[] _Author;
	delete[] _PublishingHouse;
}

Book &Book::operator = (Book &obj) {
	SetID(obj.GetID());
	SetName(obj.GetName());
	SetAuthor(obj.GetAuthor());
	SetPublishingHouse(obj.GetPublishingHouse());
	return Book(*this);
}