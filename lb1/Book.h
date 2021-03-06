﻿#pragma once

#include <cstddef>
#include <iostream>
#include <iomanip>

class Book {
private:
	int _id;
	char* _Name = NULL;
	char* _Author = NULL;
	char* _PublishingHouse = NULL;
	void _MemoryAlloc(char*&, int, char*);
public:
	int GetID();
	void SetID(int);
	char* GetName();
	void SetName(char*);
	char* GetAuthor();
	void SetAuthor(char*);
	char* GetPublishingHouse();
	void SetPublishingHouse(char*);
	void PrintBookInfo();
	Book();
	Book(Book&);
	Book(int, char*, char*, char*);
	Book &operator = (Book &obj);
	~Book();
};
