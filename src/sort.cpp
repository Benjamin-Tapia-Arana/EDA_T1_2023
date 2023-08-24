#include <iostream>
#include "sort/utils.hpp"

namespace sort{

	// INSERTSORT
	void insertSort(){

	}


	// QUICKSORT (código del profesor)
	int split_qs(float* A, int i, int j) {
		int p = getRandomInt(i, j);
		while (i < j) {
			while (i < p && A[i] <= A[p]) {i = i + 1;}
			while (j > p && A[j] >= A[p]) {j = j - 1;}
			swap(A, i, j);
			if (i == p) {p = j;}
			else if (j == p) {p = i;}
		}
		return p;
	}
	void quickSort(float* A, int i, int j) {
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}
	void quickSort(float* A, int n) {quickSort(A, 0, n - 1);}


	// MERGESORT (codigo basado en el pseudo-código del libro guía del curso)
	void merge(float* A, int i, int j, int k) {
		float Aux[j - i + 1];
		int p1, p2 = i;
		int p2 = k + 1;
		int q = 0;
		while (p1 <= k && p2 <= j) {
			if (A[p1] <= A[p2]) {
				Aux[q] = A[p1];;
				p1++;
			}
			else {
				Aux[q] = A[p2];
				p2++;
			}
			q++;
		}
		while (p1 <= k) {
			Aux[q] = A[p1];
			p1++;
			q++;
		}
		while (p2 <= j) { 
			Aux[q] = A[p2];
			p2++;
			q++;
		}
		for (p1 = i; p1 < j + 1; ++p1) {A[p1] = Aux[p1 - i];}
	}
	void mergeSort(float *A, int i = 0, int j) {
		int k = (i + j) / 2;
		if (i < j) {
			mergeSort(A, i, k);
			mergeSort(A, k + 1, j);
			merge(A, i, j, k);
		}
	}


	// RADIXSORT
	void radixSort(float* A, int i) {
		int bucket[10];
		
	}

}