#pragma once

class Book{
private:
	int id;
	vector <string> Name;
	vector <string> PublishingHouse;
	
public:
	int GetID();
	vector <string> GetName();
	vector <string> GetPublishingHouse();
	Book();
	Book(int,char*,char*);
	~Book();
};

vector <string> Book::GetName() {
	return Name;
}

vector <string> Book::GetPublishingHouse() {
	return PublishingHouse;
}

int Book::GetID() {
	return id;
}

Book::Book() {
	char Tmp[100];
	cout << "Конструктор класса без параметров" << endl;
	cout << "Номер книги:";
	cin >> id;
	cout << "Название книги:";
	cin >> Tmp;
	Name.push_back(Tmp);
	cout << "Издательство:";
	cin >> Tmp;
	PublishingHouse.push_back(Tmp);
}

Book::Book(int id_p, char *Name_p, char *PublishingHouse_p) {
	cout << "Конструктор класса с параметрами" << endl;
	id = id_p;
	Name.push_back(Name_p);
	PublishingHouse.push_back(PublishingHouse_p);
}

Book::~Book() {
	Name.clear();
	PublishingHouse.clear();
}