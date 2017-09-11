#pragma once

class Book{
private:
	int _id;
	vector <char> _Name;
	vector <char> _PublishingHouse;
	
public:
	int GetID();
	char* GetName();
	char* GetPublishingHouse();
	void PrintBookInfo();
	Book();
	Book(int,char*,char*);
	~Book();
};

char* Book::GetName() {
	char *str = new char [_Name.size() +1];
	copy(_Name.begin(), _Name.end(), str);
	str[_Name.size()] = '\0';
	return str;
	delete[] str;
}

char* Book::GetPublishingHouse() {
	char *str = new char[_PublishingHouse.size() + 1];
	copy(_PublishingHouse.begin(), _PublishingHouse.end(), str);
	str[_PublishingHouse.size()] = '\0';
	return str;
	delete[] str;
}

int Book::GetID() {
	return _id;
}

void Book::PrintBookInfo() {
	cout << "#####################" << endl;
	cout << "id" << setw(11) << ":" << _id << endl;
	cout << "Название" << setw(5) << ":";
	for (int i = 0; i < _Name.size(); i++) {
		cout << _Name[i];
	}
	cout << endl;
	cout << "Издательство" << setw(1) << ":";
	for (int i = 0; i < _PublishingHouse.size(); i++) {
		cout << _PublishingHouse[i];
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
	/////_Name.push_back(Tmp);
	cout << "Издательство:";
	cin >> Tmp;
	///_PublishingHouse.push_back(Tmp);
}

Book::Book(int id_p, char *Name_p, char *PublishingHouse_p) {
	//cout << "Конструктор класса с параметрами" << endl;
	_id = id_p;
	_Name.insert(_Name.end(), Name_p, Name_p+strlen(Name_p));
	_PublishingHouse.insert(_PublishingHouse.end(),PublishingHouse_p,PublishingHouse_p+strlen(PublishingHouse_p));
}

Book::~Book() {
	_Name.clear();
	_PublishingHouse.clear();
}