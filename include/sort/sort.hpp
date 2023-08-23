#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort{

	int split_qs(float* A, int i, int j);
	void insertSort();
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	void merge();
	void mergeSort();
	void radixSort();
}

#endif
