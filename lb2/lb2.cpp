#include <iostream>
#include <iomanip>

using namespace std;

#include "Librarian.h"

int main() {
	setlocale(0, "rus");

	int N = 6;
	int id[] = { 107,323,122,558,696,666,132 };
	char *Name[] = { "������ � �������� ���","�������� � ������� ���� ������","������� ���","���������","�����������. ��� �����","����� �����","����� ���� �������" };
	char *Author[] = { "��� ������","��� �������","������ ��������","���� ����������","����� ��������","���� ��������","��� �������" };
	char *PublishingHouse[] = { "���","���","���","���","�����","�����","���" };

	Librarian librarian(N, 7, id, Name, Author, PublishingHouse);

	while (true) {
		system("cls");
		cout << "1 - �������� ����� �� ���� ������" << endl;
		cout << "2 - ����� ���������� �����" << endl;
		switch (cin.get()) {
		case '1':
			librarian.GetAllBooksInRack();
			system("pause");
			break;
		case '2':
			librarian.GetBookByAuthor("��� �������");
			system("pause");
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}