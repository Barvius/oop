#pragma once

class Rack{
private:
	vector <int> _NumberRack;
	vector <int> _IdsBooks;
	vector <int> _Size;
public:
	Rack(int,int);
	void AddBook(int);
};

Rack::Rack(int n, int number) {
	_Size.push_back(n);
	_NumberRack.push_back(number);
}

void Rack::AddBook(int id) {
	_IdsBooks.push_back(id);
	cout << "размер полки: " << sizeof(_IdsBooks.size()) << endl;
	printing(_IdsBooks);
}