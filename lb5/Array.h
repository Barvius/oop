#pragma once
#include <iostream>
#include <iomanip>
#include <random>
#include "Vector.h"

class Array {
	friend int MaxInRow(Array&,int);
	friend float SrAr(const Array&, int);
	friend int ProizvGlDiag(Array&);
	friend float ProizvVect(const Vector&);
private:
	int** _Arr = NULL;
	int _N;
	int _M;
public:
	int GetE(int,int);
	void SetE(int, int, int);
	int GetN();
	int GetM();
	int** GetArr();
	void Print();
	Array();
	Array(int,int);
	Array(const Array&);
	~Array();
	const Array& operator = (const Array&);
	const Array& operator >> (const Array&);
	const Vector operator / (const Array&);
	const float operator - (const Vector&);
};

