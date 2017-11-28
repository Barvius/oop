#include "Vector.h"

using namespace std;

Vector::Vector(int n){
	_N = n;
	_Arr = new float[_N];
}

Vector::Vector(){

}

Vector::Vector(const Vector& obj) {
	_N = obj._N;
	_Arr = new float[_N];
	for (size_t i = 0; i < obj._N; i++) {
		_Arr[i] = obj._Arr[i];
	}
}

Vector::~Vector(){
	if (_Arr != nullptr) {
		delete[] _Arr;
	}
}

void Vector::Print() {
	for (size_t i = 0; i < _N; i++) {
		cout << setw(3) << _Arr[i] << " ";
	}
	cout << endl;
}

int Vector::GetN() {
	return _N;
}

float Vector::GetE(int i) {
	if (_N - 1 < i) {
		return 0;
	}
	return _Arr[i];
}

void Vector::SetE(int i, float val) {
	_Arr[i] = val;
}

const Vector& Vector::operator = (const Vector& obj) {
	_N = obj._N;
	_Arr = new float[_N];
	for (size_t i = 0; i < obj._N; i++) {
		_Arr[i] = obj._Arr[i];
	}
	return *this;
}