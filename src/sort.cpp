#include <iostream>
#include "sort/utils.hpp"

namespace sort{

	// INSERTSORT
	void insertSort(){

	}


	// QUICKSORT (código profesor)
	int split_qs(float* A, int i, int j){
		int p = getRandomInt(i, j);
		while (i < j) {
			while (i < p && A[i] <= A[p]){i = i + 1;}
			while (j > p && A[j] >= A[p]){j = j - 1;}
			swap(A, i, j);
			if (i == p){p = j;}
			else if (j == p){p = i;}
		}
		return p;
	}
	void quickSort(float* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}
	void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}


	// MERGESORT
	void merge(){

	}
	void mergeSort(){

	}


	// RADIXSORT
	void radixSort(){

	}

}