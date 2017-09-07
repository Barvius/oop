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
	vector <Book> _Book;
public:

	Sorter(int,int*,char**,char**);
	~Sorter();
};

Sorter::Sorter(int N, int *id, char **Name, char **PublishingHouse) {
	
	//_Book = (Book*)malloc(sizeof(Book)*N);
	for (int i = 0; i < N; i++) {
		_Book.push_back(Book(id[i], Name[i], PublishingHouse[i]));
		printing(_Book[i].GetName());
	}
}

Sorter::~Sorter() {
	_Book.clear();
}