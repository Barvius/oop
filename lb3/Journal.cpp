#include "Journal.h"

using namespace std;

void Journal::SetPeriodicity(char* str) {
	_MemoryAlloc(_Periodicity, str);
}

char* Journal::GetPeriodicity() {
	return _Periodicity;
}

void Journal::SetSubjects(char* str) {
	_MemoryAlloc(_Subjects, str);
}

char* Journal::GetSubjects() {
	return _Subjects;
}

void Journal::Info() {
	cout << "# id" << setw(12) << ":" << GetID() << endl;
	cout << "# Название" << setw(6) << ":" << GetName() << endl;
	cout << "# Тематика" << setw(6) << ":" << _Subjects << endl;
	cout << "# Переодичность" << setw(1) << ":" << _Periodicity << endl;
}

Journal::Journal() {

}

Journal::Journal(Journal &obj):Literature(obj.GetID(), obj.GetName()) {
	SetSubjects(obj._Subjects);
	SetPeriodicity(obj._Periodicity);
}

Journal::Journal(int id, char* Name, char* Subjects, char* Periodicity):Literature(id, Name) {
	SetSubjects(Subjects);
	SetPeriodicity(Periodicity);
}

Journal::~Journal(){
	delete[] _Periodicity;
	delete[] _Subjects;
}

Journal &Journal::operator = (Journal &obj) {
	SetID(obj.GetID());
	SetName(obj.GetName());
	SetSubjects(obj.GetSubjects());
	SetPeriodicity(obj.GetPeriodicity());
	return Journal(*this);
}