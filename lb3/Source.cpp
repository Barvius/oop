#include <iostream>
#include <windows.h>
#include <typeinfo>
#include "Rack.h"
#include "Book.h"
#include "Journal.h"
#include "Librarian.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N = 6;
	int idBook[] = { 107,323,122,558,696,666,132 };
	char *NameBook[] = { "Хильда и каменный лес","Придумай и нарисуй свой комикс","Каждому своё","Пропавший","Неудержимая. Моя жизнь","Магия крови","Книга моих историй" };
	char *AuthorBook[] = { "Люк Пирсон","Луи Стоуэлл","Сергей Тармашев","Мэри Торджуссен","Мария Шарапова","Лине Кобербёль","Луи Стоуэлл" };
	char *PublishingHouseBook[] = { "МИФ","МИФ","АСТ","АСТ","ЭКСМО","ЭКСМО","МИФ" };
	int idJournal[] = { 241, 412, 532 };
	char *NameJournal[] = { "Linux Format", "Юный техник", "Хакер" };
	char *SubjectsJournal[] = { "IT", "Техника", "IT" };
	char *PeriodicityJournal[] = { "Ежемесячно", "Ежемесячно", "Ежемесячно" };

	Librarian librarian;
	librarian.CreateBookshelf(N);

	for (int i = 0; i <7; i++) {
		librarian.AddLiteratureInRack(Book(idBook[i], NameBook[i], AuthorBook[i], PublishingHouseBook[i]));
	}
	for (int i = 0; i < 3; i++) {
		librarian.AddLiteratureInRack(Journal(idJournal[i], NameJournal[i], SubjectsJournal[i], PeriodicityJournal[i]));
	}

	
	while (true) {
		system("cls");
		cout << "1 - Показать книги на всех полках" << endl;
		cout << "2 - Поиск по автору книги" << endl;
		switch (cin.get()) {
		case '1':
			system("cls");
			librarian.GetAllLiteratureInRacks();
			system("pause");
			break;
		case '2':
			system("cls");
			cout << "Веедите название:";
			cin.ignore();
			char tmp[100];
			cin.getline(tmp, 100);
			librarian.GetBookByName(tmp);
			system("pause");
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}