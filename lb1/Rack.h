#pragma once

class Rack{
private:
	int _NumberRack;
	vector <int> _IdsBooks;
	int _Size;
public:
	Rack(int,int);
	void AddBook(int);
};

Rack::Rack(int n, int number) {
	_Size = n;
	_NumberRack = number;
}

void Rack::AddBook(int id) {
	_IdsBooks.push_back(id);
	cout << "размер полки: " << sizeof(_IdsBooks.size()) << endl;
	printing(_IdsBooks);
}