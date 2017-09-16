#include <iostream>
#include <iomanip>

using namespace std;

#include "Librarian.h"

int main() {
	setlocale(0, "rus");

	int N = 6;
	int id[] = { 107,323,122,558,696,666,132 };
	char *Name[] = { "Хильда и каменный лес","Придумай и нарисуй свой комикс","Каждому своё","Пропавший","Неудержимая. Моя жизнь","Магия крови","Книга моих историй" };
	char *Author[] = { "Люк Пирсон","Луи Стоуэлл","Сергей Тармашев","Мэри Торджуссен","Мария Шарапова","Лине Кобербёль","Луи Стоуэлл" };
	char *PublishingHouse[] = { "МИФ","МИФ","АСТ","АСТ","ЭКСМО","ЭКСМО","МИФ" };

	Librarian librarian(N, 7, id, Name, Author, PublishingHouse);

	while (true) {
		system("cls");
		cout << "1 - Показать книги на всех полках" << endl;
		cout << "2 - Поиск поназванию книги" << endl;
		switch (cin.get()) {
		case '1':
			librarian.GetAllBooksInRack();
			system("pause");
			break;
		case '2':
			librarian.GetBookByAuthor("Луи Стоуэлл");
			system("pause");
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}