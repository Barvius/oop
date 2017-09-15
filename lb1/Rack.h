#pragma once

class Rack {
private:
	int _NumberRack;
	Book *_Books = NULL;
	int _Size;
	int _CountBooks = 0;
public:
	Rack();
	Rack(Rack&);
	Rack(int, int);
	~Rack();
	void AddBook(Book&);
	int GetNumberRack();
	void GetBooksInRack();
	int GetAllBookById();
};

Rack::Rack(int n, int number) {
	cout << "constr rack params" << endl;
	_Size = n;
	_NumberRack = number;
}
Rack::Rack(Rack &obj) {
	cout << "constr rack obj" << endl;
	//_NumberRack = obj._NumberRack;
	//_Size = obj._Size;
	//_Books = new Book(obj._Books[0]);
}
Rack::Rack() {
	cout << "constr rack" << endl;
}
Rack::~Rack() {
	cout << "destr rack" << endl;
	if (_Books != nullptr) {
		if (_CountBooks > 1) {
			delete[] _Books;
		}
		else {
			delete _Books;
		}

	}

}

void Rack::AddBook(Book& obj) {
	if (_Books == nullptr) {
		_Books = new Book(obj);
		_CountBooks++;
	} else {
		Book *tmp_book = new Book[_CountBooks];
		for (size_t i = 0; i < _CountBooks; i++){
			tmp_book[i] = _Books[i];
		}
		if (_CountBooks > 1) {
			delete[] _Books;
		} else {
			delete _Books;
		}
		_Books = new Book[_CountBooks+1];
		for (size_t i = 0; i < _CountBooks; i++) {
			_Books[i] = tmp_book[i];
		}
		delete[] tmp_book;
		_Books[_CountBooks] = obj;
		_CountBooks++;
	}
}

void Rack::GetBooksInRack() {
	cout << _CountBooks << endl;
	for (size_t i = 0; i < _CountBooks; i++){
		_Books[i].PrintBookInfo();
		cout << endl;
	}
	
}

int Rack::GetNumberRack() {
	return _NumberRack;
}

int Rack::GetAllBookById() {
	return 1;
}