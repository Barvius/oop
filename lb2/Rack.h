#pragma once

class Rack {
private:
	int _NumberRack;
	Book *_Books = NULL;
	int _Size;
	int _CountBooks = 0;
public:
	Rack();
	//Rack(Rack&);
	Rack(int, int);
	~Rack();
	bool AddBook(Book&);
	int GetNumberRack();
	void GetAllBooksInRack();
	void GetBookByAuthor(char*);
};

Rack::Rack(int n, int number) {
	_Size = n;
	_NumberRack = number;
}

Rack::Rack() {
	
}
Rack::~Rack() {
	if (_Books != nullptr) {
		if (_CountBooks > 1) {
			delete[] _Books;
		}
		else {
			delete _Books;
		}

	}

}

bool Rack::AddBook(Book& obj) {
	if (_CountBooks == _Size) {
		return false;
	} else {
		if (_Books == nullptr) {
			_Books = new Book[1];
			_Books[0] = obj;
			_CountBooks++;
		} else {
			Book *tmp_book = new Book[_CountBooks];
			for (size_t i = 0; i < _CountBooks; i++) {
				tmp_book[i] = _Books[i];
			}
			delete[] _Books;
			_Books = new Book[_CountBooks + 1];
			for (size_t i = 0; i < _CountBooks; i++) {
				_Books[i] = tmp_book[i];
			}
			delete[] tmp_book;
			_Books[_CountBooks] = obj;
			_CountBooks++;
		}
		return true;
	}
}

void Rack::GetAllBooksInRack() {
	cout << "На полке " << _NumberRack << " (" << _CountBooks << " из " << _Size << ")" << endl;
	for (size_t i = 0; i < _CountBooks; i++) {
		_Books[i].PrintBookInfo();
		cout << endl;
	}

}

int Rack::GetNumberRack() {
	return _NumberRack;
}

void Rack::GetBookByAuthor(char* str) {
	for (size_t i = 0; i < _CountBooks; i++) {
		if (!strcmp(_Books[i].GetAuthor(), str)) {
			cout << "Книга на полке " << _NumberRack << endl;
			_Books[i].PrintBookInfo();
		}
	}
}