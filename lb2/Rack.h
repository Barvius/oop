#pragma once

#include "Book.h"

#include <iostream>
#include <iomanip>
#include <cstddef>

class Rack {
private:
	int _NumberRack;
	int _Size;
	int _CountBooks = 0;
	Book *_Books = NULL;
public:
	bool AddBook(Book&);
	int GetNumberRack();
	void GetAllBooksInRack();
	void GetBookByAuthor(char*);
	Rack();
	Rack(int, int);
	~Rack();
	
};
