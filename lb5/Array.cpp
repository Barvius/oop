#include "Array.h"

using namespace std;

void Array::Print() {
	for (size_t i = 0; i < _N; i++) {
		for (size_t j = 0; j < _M; j++) {
			cout << setw(3) << _Arr[i][j] << " ";
		}
		cout << endl;
	}
}

Array::Array(int n, int m){
	_N = n;
	_M = m;
	_Arr = new int*[_N];
	for (size_t i = 0; i < _N; i++){
		_Arr[i] = new int[_M];
	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> rand(-10,10);
	for (size_t i = 0; i < _N; i++){
		for (size_t j = 0; j < _M; j++){
			_Arr[i][j] = rand(gen);
		}

	}
}

Array::Array() {

}

Array::Array(Array& obj) {
	_N = obj.GetN();
	_M = obj.GetM();
	_Arr = new int*[_N];
	for (size_t i = 0; i < _N; i++) {
		_Arr[i] = new int[_M];
	}
	for (size_t i = 0; i < obj.GetN(); i++) {
		for (size_t j = 0; j < obj.GetM(); j++) {
			_Arr[i][j] = obj.GetE(i,j);
		}
	}
}

Array::~Array(){
	if (_Arr != nullptr) {
	for (size_t i = 0; i < _N; i++) {
		delete[] _Arr[i];
	}
	delete[] _Arr;
	}
}

const Array& Array::operator >> (const Array& obj) {
	Array tmp;
	_N = obj._N;
	_M = obj._M;
	_Arr = new int*[_N];
	for (size_t i = 0; i < _N; i++) {
		_Arr[i] = new int[_M];
	}
	for (size_t i = 0; i < obj._N; i++) {
		for (size_t j = 0; j < obj._M; j++) {
			_Arr[i][j] = obj._Arr[i][j];
		}
	}
	for (size_t i = 0; i < obj._N; i++) {
		int a = MaxInRow(*this, i);
		int b = MaxInRow(tmp, i);
		tmp.SetE(i,b, this->GetE(i,a));
	}
	return obj;
}

const Array& Array::operator = (const Array& obj) {
	_N = obj._N;
	_M = obj._M;
	_Arr = new int*[_N];
	for (size_t i = 0; i < _N; i++) {
		_Arr[i] = new int[_M];
	}
	for (size_t i = 0; i < obj._N; i++) {
		for (size_t j = 0; j < obj._M; j++) {
			_Arr[i][j] = obj._Arr[i][j];
		}
	}
	return *this;
}

const Vector Array::operator / (const Array& obj) {
	int N = this->GetN();
	if (this->GetN() > obj._N) {
		N = obj._N;
	}
	Vector tmp(N);
	for (size_t i = 0; i < N; i++) {
		tmp.SetE(i, SrAr(*this, i) / SrAr(obj, i));
	}
	tmp.Print();
	return tmp;
}

float Array::operator - (Vector& obj) {
	return fabs(ProizvGlDiag(*this))-fabs(ProizvVect(obj));
}

int Array::GetN() {
	return _N;
}

int Array::GetM() {
	return _M;
}

int** Array::GetArr() {
	return _Arr;
}

int Array::GetE(int i, int j) {
	if (_N-1 < i || _M-1 < j){
		return 0;
	}
	return _Arr[i][j];
}

void Array::SetE(int i, int j, int val) {
	_Arr[i][j] = val;
}