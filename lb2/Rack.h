#pragma once

#include "Book.h"

#include <cstddef>

class Rack {
private:
	int _NumberRack;
	Book *_Books = NULL;
	int _Size;
	int _CountBooks = 0;
public:
	bool AddBook(Book&);
	int GetNumberRack();
	void GetAllBooksInRack();
	void GetBookByAuthor(char*);
	Rack();
	Rack(int, int);
	~Rack();
	
};
