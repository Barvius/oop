#include "Literature.h"
using namespace std;

void Literature::_MemoryAlloc(char *&arr, char* str) {
	if (arr != nullptr) {
		delete[] arr;
	}
	arr = new char[strlen(str)+1];
	strcpy(arr, str);
}

int Literature::GetID() {
	return _id;
}

void Literature::SetID(int id) {
	_id = id;
}

char* Literature::GetName() {
	return _Name;
}

void Literature::SetName(char* str) {
	_MemoryAlloc(_Name,str);
}

Literature::Literature(){

}

Literature::Literature(int id, char* name) {
	SetID(id);
	SetName(name);
}

Literature::~Literature(){
	delete[] _Name;
}
