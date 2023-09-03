#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

#include <string>

namespace sort{

	int split_qs(int* A, int i, int j);
	void insertSort();
	void quickSort(int* A, int i, int j);
	void quickSort(int* A, int n);
	void merge(int* A, int i, int j, int k);
	void mergeSort(int* A, int i, int j);
	void ordering(int* A, int i, int pos, int *bucket);
	void radixSort(int* A, int i, int pos = 5, int* bucket = nullptr);
}

#endif
