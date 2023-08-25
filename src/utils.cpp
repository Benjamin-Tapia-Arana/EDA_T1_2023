#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "sort/utils.hpp"

namespace sort{

	int* createArray(int n){
		return new int[n];
	}

	int* createRandomArray(int n){
		int* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] =  std::rand() / static_cast<float>(RAND_MAX);
		}
		return A;
	}

	int* createRandomIntArray(int n, int minVal, int maxVal){
		int* A = createArray(n);
		for (int i = 0; i < n; i++){
			A[i] = getRandomInt(minVal, maxVal);
		}
		return A;
	}

	void deleteArray(int* A){
		delete[] A;
	}

	void printArray(int* A, int n){
		for (int i = 0; i < n; i++){
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;
	}

	void setAll(float* A, int n, float value){
		for (int i = 0; i < n; i++){
			A[i] =  value;
		}
	}

	void swap(int* A, int i, int j){
		int aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	int getRandomInt(int min, int max){
		float a = rand() / static_cast<float>(RAND_MAX);
		return static_cast<int>(a * (max - min) + min + 0.5);
	}

	int* linspace(int max, int n_parts){
		int* V = new int[n_parts];
		int part_size = max / n_parts;
		for(int i = 1; i <= n_parts; i++){
			V[i - 1] = part_size * i;
		}
		return V;
	}
	
	int maxLengthNumber(int* A, int n) {
		int largestN = 0;
		for (int i = 0; i < n; i++) {if (A[i] > largestN) {largestN = A[i];}}
		return largestN;
	}

	int maxLength(int* A, int n) {
		int largestN = 0;
		int len = 0;
		for (int i = 0; i < n; i++) {if (A[i] > largestN) {largestN = A[i];}}
		while (largestN > 0) {
			largestN /= 10;
			len++;
		}
		
		return len + 1;
	}
}
