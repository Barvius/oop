#pragma once
#include <iomanip>
#include <iostream>
#include "Literature.h"

class Journal :public Literature{
private:
	char* _Periodicity = NULL;
	char* _Subjects = NULL;
public:
	void SetPeriodicity(char*);
	char* GetPeriodicity();
	void SetSubjects(char*);
	char* GetSubjects();
	void Info();
	Journal &operator = (Journal &obj);
	Journal();
	Journal(Journal&);
	Journal(int, char*, char*, char*);
	~Journal();
};

