#pragma once

class Book{
private:
	int id;
	char *Name = new char;
	char *PublishingHouse = new char;

public:
	int GetID();
	char *GetName();
	char *GetPublishingHouse();
	Book();

};

char *Book::GetName() {
	return Name;
}

char *Book::GetPublishingHouse() {
	return PublishingHouse;
}

int Book::GetID() {
	return id;
}

Book::Book() {
	char Tmp[100];
	system("Color F0");
	cout << "����������� ������ ��� ����������" << endl;
	cout << "����� �����:";
	cin >> id;
	cout << "�������� �����:";
	cin >> Tmp;
	strcpy(Name, Tmp);
	memset(Tmp, 0, 100);
	cout << "������������:";
	cin >> Tmp;
	strcpy(PublishingHouse, Tmp);
	free(Tmp);
}