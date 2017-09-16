#pragma once

#include "Rack.h"

class Librarian {
private:
	int _CountRacks;
	Rack *_Racks;
public:
	void GetAllBooksInRack();
	void GetBookByAuthor(char*);
	void AddBookInRack(Book&, int);
	Librarian(int, int, int*, char**, char**, char**);
	~Librarian();
};
