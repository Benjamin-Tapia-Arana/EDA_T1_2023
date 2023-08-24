#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort{

	int split_qs(float* A, int i, int j);
	void insertSort();
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	void merge(float *A, int i, int j, int k);
	void mergeSort(float *A, int i = 0, int j);
	void radixSort();
}

#endif
