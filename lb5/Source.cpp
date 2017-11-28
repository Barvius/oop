#include <iostream>
#include "Array.h"
#include "Vector.h"
#include "Friends.h"

using namespace std;

int main() {
	Array M1(4,4), M2(5,5);
	M1.Print();
	cout << endl;
	M2.Print();
	cout << endl;
	Array M3 = M1 >> M2;
	M3.Print();
	//Array M4;
	//M1 >> M2 = M4;
	Vector V = M1 / M2;
	V.Print();
	float K = M1 - V;
	cout << K << endl;
	cout << (M1-(M3/(M2>>M1))) << endl;
	system("pause");
	return 0;
}