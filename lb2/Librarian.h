#pragma once

#include "Rack.h"

#include <time.h>
#include <iostream>

class Librarian {
private:
	int _CountRacks;
	Rack *_Racks = NULL;
public:
	void GetAllBooksInRacks();
	void GetBookByAuthor(char*);
	void AddBookInRack(Book&, int);
	Librarian(int, int, int*, char**, char**, char**);
	~Librarian();
};
