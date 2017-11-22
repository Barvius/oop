#include "Vector.h"

using namespace std;

Vector::Vector(int n){
	_N = n;
	_Arr = new float[_N];
}

Vector::Vector(){

}

Vector::Vector(Vector& obj) {
	_N = obj.GetN();
	_Arr = new float[_N];
	for (size_t i = 0; i < obj.GetN(); i++) {
		_Arr[i] = obj.GetE(i);
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

Vector& Vector::operator = (Vector& obj) {
	_N = obj.GetN();
	_Arr = new float[_N];
	for (size_t i = 0; i < obj.GetN(); i++) {
		_Arr[i] = obj.GetE(i);
	}
	return *this;
}