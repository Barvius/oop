#pragma once

#include <vector>
#include <string>

#include "Book.h"
#include "Rack.h"



class Sorter {
private:
	Rack *_Racks;
public:
	void GetAllBooksInRack();
	void GetBookByName(char*);
	Sorter(int,int,int*,char**,char**,char**);
	~Sorter();
};

void Sorter::GetBookByName(char *Name) {
	/*
	int id;
	for (int i = 0; i < _Books.size(); i++) {
		if (!strcmp(_Books[i].GetName(),Name)) {
			id = _Books[i].GetID();
			for (int j = 0; j < _Racks.size();j++) {
				vector <int> ids = _Racks[j].GetAllBookById();
				for (int k = 0; k < ids.size();k++) {
					if (ids[k] == id) {
						cout << "книга на полке № " << _Racks[j].GetNumberRack() << endl;
						_Books[i].PrintBookInfo();
					}
				}
			}
		}
		
	}
	*/
}

void Sorter::GetAllBooksInRack() {
	/*
	for (int j = 0; j < _Racks.size(); j++) {
		vector <int> ids = _Racks[j].GetAllBookById();
		cout << "| на полке " << j + 1 << " -- " << ids.size() << " книг |" << endl;
		for (auto r = ids.begin(); r != ids.end(); r++) {
			for (int b = 0; b < _Books.size(); b++) {
				if (_Books[b].GetID() == *r) {
					_Books[b].PrintBookInfo();
				}
			}

		}
	}
	*///
	//for (int j = 0; j < _Books.size(); j++) {
	//	_Books[j].PrintBookInfo();
	//}
}

Sorter::Sorter(int RackNum, int BookNum, int *id, char **Name, char **Author, char **PublishingHouse) {
	_Racks = new Rack[RackNum];
	for (int i = 0; i < RackNum; i++) {
		_Racks[i] = Rack(10, i + 1);
	}
	for (int i = 0; i < BookNum; i++) {
		for (size_t r = 0; r < RackNum; r++) {
			if (_Racks[r].GetNumberRack() == id[i] / 100) {
				_Racks[r].AddBook(Book(id[i], Name[i], Author[i], PublishingHouse[i]));
			}
		}
	}
	for (int i = 0; i < RackNum; i++) {
		cout << "список книг на полке " << i+1 << endl;
		_Racks[i].GetBooksInRack();
	}
	
}

Sorter::~Sorter() {
	cout << "sorter destr" << endl;
	delete[] _Racks;
}