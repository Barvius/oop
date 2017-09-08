#pragma once

class Book{
private:
	int _id;
	vector <string> _Name;
	vector <string> _PublishingHouse;
	
public:
	int GetID();
	vector <string> GetName();
	vector <string> GetPublishingHouse();
	void PrintBookInfo();
	Book();
	Book(int,char*,char*);
	~Book();
};

vector <string> Book::GetName() {
	return _Name;
}

vector <string> Book::GetPublishingHouse() {
	return _PublishingHouse;
}

int Book::GetID() {
	return _id;
}

void Book::PrintBookInfo() {
	cout << "#####################" << endl;
	cout << "id" << setw(11) << ":" << _id << endl;
	cout << "Название" << setw(5) << ":"; //<< _Name.data() << endl;
	for (auto i = _Name.begin(); i != _Name.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
	cout << "Издательство" << setw(1) << ":";
	for (auto i = _PublishingHouse.begin(); i != _PublishingHouse.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl << "#####################" << endl;
}

Book::Book() {
	char Tmp[100];
	//cout << "Конструктор класса без параметров" << endl;
	cout << "Номер книги:";
	cin >> _id;
	cout << "Название книги:";
	cin >> Tmp;
	_Name.push_back(Tmp);
	cout << "Издательство:";
	cin >> Tmp;
	_PublishingHouse.push_back(Tmp);
}

Book::Book(int id_p, char *Name_p, char *PublishingHouse_p) {
	//cout << "Конструктор класса с параметрами" << endl;
	_id = id_p;
	_Name.push_back(Name_p);
	_PublishingHouse.push_back(PublishingHouse_p);
}

Book::~Book() {
	_Name.clear();
	_PublishingHouse.clear();
}