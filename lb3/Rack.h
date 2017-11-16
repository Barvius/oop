#pragma once

#include "Book.h"
#include "Journal.h"

#include <iostream>
#include <iomanip>
#include <cstddef>

class Rack {
private:
	int _NumberRack;
	int _Size;
	int _CountBooks = 0;
	Literature **_Literature = NULL;
	void _Move();
public:
	bool AddLiterature(Journal&);
	bool AddLiterature(Book&);
	int GetNumberRack();
	void GetAllLiteratureInRack();
	void GetBookByName(char*);
	Rack();
	Rack(int, int);
	~Rack();
};
