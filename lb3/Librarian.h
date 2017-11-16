#pragma once

#include "Rack.h"

#include <time.h>
#include <iostream>

class Librarian {
private:
	int _CountRacks;
	Rack *_Racks = NULL;
public:
	void GetAllLiteratureInRacks();
	void GetAllLiteratureInRack(int);
	void CreateBookshelf(int);
	void GetBookByName(char*);
	void AddLiteratureInRack(Book&);
	void AddLiteratureInRack(Journal&);
	Librarian();
	~Librarian();
};