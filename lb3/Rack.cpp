#include "Rack.h"

using namespace std;

void Rack::_Move() {
	Literature **tmp = new Literature *[_CountBooks];
	for (size_t i = 0; i < _CountBooks; i++) {
		tmp[i] = _Literature[i];
	}
	delete[] _Literature;
	_Literature = new Literature *[_CountBooks + 1];
	for (size_t i = 0; i < _CountBooks; i++) {
		_Literature[i] = tmp[i];
	}
	delete[] tmp;
	_CountBooks++;
}

bool Rack::AddLiterature(Journal& obj) {
	if (_CountBooks == _Size) {
		return false;
	} else {
		_Move();
		_Literature[_CountBooks-1] = new Journal(obj);
		return true;
	}
}

bool Rack::AddLiterature(Book& obj) {
	if (_CountBooks == _Size) {
		return false;
	} else {
		_Move();
		_Literature[_CountBooks-1] = new Book(obj);
		return true;
	}
}

void Rack::GetAllLiteratureInRack() {
	cout << "На полке " << _NumberRack << " (" << _CountBooks << " из " << _Size << ")" << endl;
	for (size_t i = 0; i < _CountBooks; i++) {
		_Literature[i]->Info();
		cout << endl;
	}

}

int Rack::GetNumberRack() {
	return _NumberRack;
}

void Rack::GetBookByName(char* str) {
	for (size_t i = 0; i < _CountBooks; i++) {
		if (!strcmp(_Literature[i]->GetName(), str)) {
			cout << "Книга на полке " << _NumberRack << endl;
			_Literature[i]->Info();
		}
	}
}

Rack::Rack() {

}

Rack::Rack(int n, int number) {
	_Size = n;
	_NumberRack = number;
}

Rack::~Rack() {
	for (int i = 0; i < _CountBooks; i++) {
		delete[] _Literature[i];
	}
	delete[] _Literature;
}
