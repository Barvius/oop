#pragma once

#include <vector>
#include <string>

#include "Book.h"
#include "Rack.h"



class Sorter {
private:
	int _CountRacks;
	Rack *_Racks;
public:
	void GetAllBooksInRack();
	void GetBookByAuthor(char*);
	void AddBookInRack(Book&,int);
	Sorter(int,int,int*,char**,char**,char**);
	~Sorter();
};

void Sorter::GetBookByAuthor(char* str) {
	cout << "поиск" << endl;
	for (int i = 0; i < _CountRacks; i++) {
		_Racks[i].GetBookByAuthor(str);
	}
}

void Sorter::GetAllBooksInRack() {
	for (int i = 0; i < _CountRacks; i++) {
		//cout << "список книг на полке " << i + 1 << endl;
		_Racks[i].GetAllBooksInRack();
	}
}

Sorter::Sorter(int RackNum, int BookNum, int *id, char **Name, char **Author, char **PublishingHouse) {
	_CountRacks = RackNum;
	_Racks = new Rack[_CountRacks];
	for (int i = 0; i < _CountRacks; i++) {
		_Racks[i] = Rack(rand() % 5 + 1, i + 1);
	}
	for (int i = 0; i < BookNum; i++) {
		for (size_t r = 0; r < _CountRacks; r++) {
			if (_Racks[r].GetNumberRack() == id[i] / 100) {
				this->AddBookInRack(Book(id[i], Name[i], Author[i], PublishingHouse[i]),r);
			}
		}
	}
}

void Sorter::AddBookInRack(Book &obj, int RackNum) {
	if (!_Racks[RackNum].AddBook(obj)) {
		int rack_new;
		srand(time(NULL));
		do {
			do {
				rack_new = rand() % _CountRacks + 1;
			} while (rack_new == RackNum);
		} while (!_Racks[rack_new - 1].AddBook(obj));
	}
}

Sorter::~Sorter() {
	cout << "sorter destr" << endl;
	delete[] _Racks;
}