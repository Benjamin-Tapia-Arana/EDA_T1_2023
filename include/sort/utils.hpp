#ifndef SORT_UTILS_HPP
#define SORT_UTILS_HPP

namespace sort{
	
	int* createArray(int n);
	int* createRandomArray(int n);
	int* createRandomIntArray(int n, int minVal = 0, int maxVal = 100);
	void deleteArray(int* A);
	void printArray(int* A, int n);
	void setAll(float* A, int n, float value);
	void swap(int* A, int i, int j);
	int getRandomInt(int min, int max);
	int* linspace(int max, int n_parts);
	int maxLengthNumber(int* A, int n);
	int maxLength(int* A, int n);
}

#endif
