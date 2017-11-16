#pragma once
//#include"Book.h"
#include <iostream>
#include <cstddef>

class Literature{
protected:
	void _MemoryAlloc(char*&, char*);
private:
	int _id;
	char* _Name = NULL;	
public:
	int GetID();
	void SetID(int);
	char* GetName();
	void SetName(char*);
	virtual void Info() = 0;
	Literature();
	Literature(int,char*);
	virtual ~Literature();
};

