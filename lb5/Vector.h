#pragma once
#include <iostream>
#include <iomanip>

class Vector{
private:
	float* _Arr = NULL;
	int _N;
public:
	float GetE(int);
	void SetE(int, float);
	int GetN();
	void Print();
	Vector();
	Vector(Vector&);
	Vector(int);
	~Vector();
	Vector& operator = (Vector&);
};

