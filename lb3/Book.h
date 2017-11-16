#pragma once
#include <iomanip>
#include <iostream>
#include "Literature.h"

class Book :public Literature{
private:
	char* _Author = NULL;
	char* _PublishingHouse = NULL;
public:
	char* GetAuthor();
	void SetAuthor(char*);
	char* GetPublishingHouse();
	void SetPublishingHouse(char*);
	void Info();
	Book &operator = (Book &obj);
	Book();
	Book(Book&);
	Book(int, char*, char*, char*);
	~Book();
};

