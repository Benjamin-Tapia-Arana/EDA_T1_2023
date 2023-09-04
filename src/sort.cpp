#include <iostream>
#include <cmath>
#include "sort/utils.hpp"

namespace sort{

	int tolerance = 1e-9;

	// INSERTSORT
	void insertSort(){

	}

	// QUICKSORT (código del profesor)
	int split_qs(int* A, int i, int j) {
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
	void quickSort(int* A, int i, int j) {
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}
	void quickSort(int* A, int n) {quickSort(A, 0, n - 1);}

	// MERGESORT (codigo basado en el pseudo-código del libro guía del curso)
	void merge(int* A, int i, int j, int k) {
		int Aux[j - i + 1];
		int p1 = i;
		int p2 = k + 1;
		int q = 0;
		while (p1 <= k && p2 <= j) {
			if (A[p1] + tolerance <= A[p2]) {
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
		for (p1 = i; p1 <= j; p1++) {A[p1] = Aux[p1 - i];}
	}
	void mergeSort(int *A, int i, int j) {
		int k = (i + j) / 2;
		if (i < j) {
			mergeSort(A, i, k);
			mergeSort(A, k + 1, j);
			merge(A, i, j, k);
		}
	}

	// RADIXSORT
	void ordering(int* A, int i, int pos, int* bucket) {
		int* Aux = new int[i];
		for (int j = 0; j < 10; j++) {bucket[j] = 0;}
		for (int j = 0; j < i; j++) {Aux[j] = 0;}
		for (int j = 0; j < i; j++) {bucket[(A[j] / pos) % 10]++;}
		for (int j = 1; j < 10; j++) {bucket[j] += bucket[j - 1];}
		for (int j = i - 1; j >= 0; j--) {
			Aux[bucket[(A[j] / pos) % 10] - 1] = A[j];
			bucket[(A[j] / pos) % 10]--;
		}
		for (int j = 0; j < i; j++) {A[j] = Aux[j];}
		delete[] Aux;
		Aux = nullptr;
	}
	void radixSort(int* A, int i, int pos = 5, int* bucket = nullptr) {
		if (pos == 5) {pos = pow(10, maxLength(A, i));}
		if (bucket == nullptr) {bucket = new int[10];}
		if (pos > 0) {
			radixSort(A, i, pos / 10, bucket);
			ordering(A, i, pos, bucket);
		}
		if (pos == 10) {delete[] bucket;}
	}
}
