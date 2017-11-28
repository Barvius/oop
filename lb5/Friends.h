#pragma once
int MaxInRow(Array& arr, int row) {
	if (arr.GetN() <= row) {
		return 0;
	}
	int max = -100, index = 0;
	for (size_t i = 0; i < arr._M; i++) {
		if (arr._Arr[row][i] > max) {
			max = arr._Arr[row][i];
			index = i;
		}
	}
	return index;
}

float SrAr(const Array& arr, int row) {
	float Sr = 0;
	for (size_t i = 0; i < arr._M; i++) {
		Sr += arr._Arr[row][i];
	}
	return Sr / arr._M;
}

int ProizvGlDiag(Array& arr) {
	int tmp = 1;
	if (arr._N != arr._M) {
		return 0;
	}
	else {
		for (size_t i = 0; i < arr._N; i++) {
			tmp *= arr.GetE(i, i);
		}
	}
	return tmp;
}

float ProizvVect(const Vector& vect) {
	int tmp = 1;
	for (size_t i = 0; i < vect._N; i++) {
		tmp *= vect._Arr[i];
	}
	return tmp;
}
