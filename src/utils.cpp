#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "sort/utils.hpp"

namespace sort{

	void printArray(int* A, int n){
		for (int i = 0; i < n; i++){
			std::cout<<A[i]<<" ";
		}
		std::cout<<std::endl;
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
