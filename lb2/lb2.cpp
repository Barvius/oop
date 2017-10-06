#include <iostream>
#include <windows.h>
#include "Librarian.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int N = 6;
	int id[] = { 107,323,122,558,696,666,132 };
	char *Name[] = { "Хильда и каменный лес","Придумай и нарисуй свой комикс","Каждому своё","Пропавший","Неудержимая. Моя жизнь","Магия крови","Книга моих историй" };
	char *Author[] = { "Люк Пирсон","Луи Стоуэлл","Сергей Тармашев","Мэри Торджуссен","Мария Шарапова","Лине Кобербёль","Луи Стоуэлл" };
	char *PublishingHouse[] = { "МИФ","МИФ","АСТ","АСТ","ЭКСМО","ЭКСМО","МИФ" };

	Librarian librarian(N, 7, id, Name, Author, PublishingHouse);

	while (true) {
		system("cls");
		cout << "1 - Показать книги на всех полках" << endl;
		cout << "2 - Поиск по автору книги" << endl;
		switch (cin.get()) {
		case '1':
			system("cls");
			librarian.GetAllBooksInRacks();
			system("pause");
			break;
		case '2':
			system("cls");
			cout << "Веедите автора:";
			cin.ignore();
			char tmp[100];
			cin.getline(tmp, 100);
			librarian.GetBookByAuthor(tmp);
			system("pause");
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}