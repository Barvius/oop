#pragma once
//#define _SCL_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>

void printing(vector <string> text) {
	for (auto i = text.begin(); i != text.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}
void printing(vector <int> text) {
	for (auto i = text.begin(); i != text.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

#include "Book.h"
#include "Rack.h"



class Sorter {
private:
	vector <Book> _Books;
	vector <Rack> _Racks;
public:

	Sorter(int,int*,char**,char**);
	~Sorter();
};

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
	for (int j = 0; j < N; j++) {
		vector <int> ids = _Racks[j].GetAllBookById();
		cout << "на полке " << j + 1 << " -- " << ids.size() << " книг" << endl;
		for (auto r = ids.begin(); r != ids.end(); r++) {
			for (int b = 0; b < _Books.size(); b++) {
				if (_Books[b].GetID() == *r) {
					_Books[b].PrintBookInfo();
				}
			}
			
		}
	}
}

Sorter::~Sorter() {
	_Books.clear();
	_Racks.clear();
}