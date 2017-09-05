// lb1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int size(char *arr) {
	int i = 0;
	while (arr[i]){
		i++;
	}
	return i;
}
using namespace std;


#include "Book.h"


int main(){
	setlocale(0, "rus");
	Book Book_1;
	cout << Book_1.GetName() << endl;
	system("pause");
    return 0;
}

