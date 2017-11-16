#include "Librarian.h"
using namespace std;

void Librarian::GetBookByName(char* str) {
	cout << str << endl;
	for (int i = 0; i < _CountRacks; i++) {
		_Racks[i].GetBookByName(str);
	}
}

void Librarian::GetAllLiteratureInRacks() {
	for (int i = 0; i < _CountRacks; i++) {
		_Racks[i].GetAllLiteratureInRack();
	}
}

void Librarian::GetAllLiteratureInRack(int RackNum) {
	_Racks[RackNum - 1].GetAllLiteratureInRack();
}

void Librarian::CreateBookshelf(int RackNums) {
	_CountRacks = RackNums;
	_Racks = new Rack[RackNums];
	for (int i = 0; i < _CountRacks; i++) {
		_Racks[i] = Rack(rand() % 7 + 1, i + 1);

	}
}

void Librarian::AddLiteratureInRack(Book &obj) {
	int RackNum = obj.GetID() / 100;
	if (!_Racks[RackNum-1].AddLiterature(obj)) {
		int rack_new;
		srand(time(NULL));
		do {
			do {
				rack_new = rand() % _CountRacks + 1;
			} while (rack_new == RackNum);
		} while (!_Racks[rack_new - 1].AddLiterature(obj));
	}
}

void Librarian::AddLiteratureInRack(Journal &obj) {
	int RackNum = obj.GetID() / 100;
	if (!_Racks[RackNum-1].AddLiterature(obj)) {
		int rack_new;
		srand(time(NULL));
		do {
			do {
				rack_new = rand() % _CountRacks + 1;
			} while (rack_new == RackNum);
		} while (!_Racks[rack_new - 1].AddLiterature(obj));
	}
}

Librarian::Librarian() {

}

Librarian::~Librarian() {
	delete[] _Racks;
}