#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

void testSort(int max_size, int n_sizes){
	int* sizes = sort::linspace(max_size, n_sizes);
	int* A = nullptr;
	int n = 0;
	for (int i = 0; i < n_sizes; i++){
		n = sizes[i];
		A = sort::createRandomIntArray(n, 0, 100);
		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here
		sort::quickSort(A, n);
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		sort::deleteArray(A);
		std::cout << " [" << n << "," << elapsed << "]" << std::endl;
	}
	delete[] sizes;
}


//int main(int nargs, char** nvargs){
//	int n_sizes = 10;
//	int max_size = 100000;
//	testSort(max_size, n_sizes);
//	return 0;
//}


int main(int nargs, char** args){

	std::srand(std::time(nullptr));
	int n = 10;
	int* A = sort::createRandomIntArray(n, 0, 1000);
	int C1[10];
	int C2[10];
	int C3[10];
	int C4[10];
	std::copy(A, A + n, C1);
	std::copy(A, A + n, C2);
	std::copy(A, A + n, C3);
	std::copy(A, A + n, C4);
	sort::printArray(A, n);
//	auto start = std::chrono::high_resolution_clock::now();
	sort::quickSort(C1, 0, n - 1);
	sort::printArray(C1, n);
	sort::mergeSort(C2, 0, n - 1);
	sort::printArray(C2, n);
	sort::radixSort(C3, n);
	sort::printArray(C3, n);
//	sort::deleteArray(A);
//	auto end = std::chrono::high_resolution_clock::now();
//	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	return 0;
}
