// lb1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
  

using namespace std;

#include "Sorter.h"

int main() {
	setlocale(0, "rus");
	//system("Color F0");
	//ofstream outfile;
	//outfile.open("db.txt");
	//Sorter Sorter_1("db.txt");
	int N = 6;
	int id[] = { 107,323,122,558,696,666 };
	char *Name[] = { "������ � �������� ���","�������� � ������� ���� ������","������� ���","���������","�����������. ��� �����","����� �����" };
	char *Author[] = {"��� ������","��� �������","������ ��������","���� ���������� ","����� ��������","���� ��������"};
	char *PublishingHouse[] = { "���","���","���","���","�����","�����" };

	Sorter Sort(N, 6, id, Name,Author, PublishingHouse);
	/*
	Book a(id[0], Name[0], PublishingHouse[0]);
	Book b(id[1], Name[1], PublishingHouse[1]);
	a.PrintBookInfo();
	b.PrintBookInfo();
	a = b;
	a.PrintBookInfo();
	*/
	//Rack polka(10,1);
	//polka.AddBook(Book(id[0], Name[0], PublishingHouse[0]));
	//polka.AddBook(Book(id[1], Name[1], PublishingHouse[1]));
	//polka.GetBooksInRack();
	/*
	while (true) {
		system("cls");
		cout << "1 - �������� ����� �� ���� ������" << endl;
		cout << "2 - ����� ���������� �����" << endl;
		switch (cin.get()) {
		case '1':
			Sort.GetAllBooksInRack();
			system("pause");
			break;
		case '2':
			Sort.GetBookByName("������ � �������� ���");
			system("pause");
			break;
		default:
			break;
		}

	}
	*/


	//Rack polka(6,2);
	//polka.AddBook(2);
	//polka.AddBook(5);
	/*

	Book Book_1;
	Book Book_2(12, "��", "re");
	cout << Book_1.GetName() << endl;
	cout << Book_2.GetName() << endl;
	*/
	//free(Name);
	//free(PublishingHouse);
	
	system("pause");
	return 0;
}

