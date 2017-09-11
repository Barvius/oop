#pragma once

#include <vector>
#include <string>

#include "Book.h"
#include "Rack.h"



class Sorter {
private:
	vector <Book> _Books;
	vector <Rack> _Racks;
public:
	void GetAllBooksInRack();
	void GetBookByName(char*);
	Sorter(int,int*,char**,char**);
	~Sorter();
};

void Sorter::GetBookByName(char *Name) {
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
}

void Sorter::GetAllBooksInRack() {
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
}

Sorter::Sorter(int N, int *id, char **Name, char **PublishingHouse) {
	for (int i = 0; i < N; i++){
		_Racks.push_back(Rack(10,i+1));
	}
	char tmp[10], num[1];
	for (int i = 0; i < N; i++) {
		_Books.push_back(Book(id[i], Name[i], PublishingHouse[i]));
		sprintf(tmp, "%d",id[i]);
		memcpy(num,tmp,1);
		for (int j = 0; j < N; j++){
			if (_Racks[j].GetNumberRack() == atoi(num)) {
				_Racks[j].AddBook(id[i]);
			}
		}
	}
	
}

Sorter::~Sorter() {
	_Books.clear();
	_Racks.clear();
}