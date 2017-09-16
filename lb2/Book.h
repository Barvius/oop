#pragma once

#include <cstddef>

class Book {
private:
	int _id;
	char* _Name = NULL;
	char* _Author = NULL;
	char* _PublishingHouse = NULL;
	void MemoryAlloc(char *&, int);
	void MemoryClear(char *&);
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
