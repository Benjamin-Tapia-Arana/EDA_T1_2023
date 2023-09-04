#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> fileReader(const std::string& filename) {
	std::ifstream archivo(filename);
	std::vector<int> A1;
	std::string line;

	if (!archivo.is_open()) {
		std::cout << "Error leyendo el archivo" << std::endl;
		return A1;
	}

    while (std::getline(archivo, line)) {
        int valor = std::stoi(line);
        A1.push_back(valor);
    }
    archivo.close();

    return A1;
}

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

void orderArray(std::string sort, int* A, int n) {
	int msTime;
	std::string sortAlgorithm;

	if (std::string(sort) == "Q") {
		auto start = std::chrono::high_resolution_clock::now();
		sort::quickSort(A, 0, n - 1);
		auto end = std::chrono::high_resolution_clock::now();
		int msTime = getElapsedTime(start, end);
		sortAlgorithm = "quickSort";
		float sTime = static_cast<float>(msTime) / 1000;
		std::cout << sortAlgorithm << " time: " << msTime << " ms (" << sTime << "s)" << std::endl;
	}

	if (std::string(sort) == "M") {
		auto start = std::chrono::high_resolution_clock::now();
		sort::mergeSort(A, 0, n - 1);
		auto end = std::chrono::high_resolution_clock::now();
		int msTime = getElapsedTime(start, end);
		sortAlgorithm = "mergeSort";
		float sTime = static_cast<float>(msTime) / 1000;
		std::cout << sortAlgorithm << " time: " << msTime << " ms (" << sTime << "s)" << std::endl;
	}

	if (std::string(sort) == "R") {
		auto start = std::chrono::high_resolution_clock::now();
		sort::radixSort(A, n);
		auto end = std::chrono::high_resolution_clock::now();
		int msTime = getElapsedTime(start, end);
		sortAlgorithm = "radixSort";
		float sTime = static_cast<float>(msTime) / 1000;
		std::cout << sortAlgorithm << " time: " << msTime << " ms (" << sTime << "s)" << std::endl;
	}

	// if (std::string(sort) == "I") {
	// 	auto start = std::chrono::high_resolution_clock::now();
	// 	sort::insertSort();
	// 	auto end = std::chrono::high_resolution_clock::now();
	// 	int msTime = getElapsedTime(start, end);
	// 	sortAlgorithm = "insertSort";
	//	float sTime = static_cast<float>(msTime) / 1000;
	//	std::cout << sortAlgorithm << " time: " << msTime << " ms (" << sTime << "s)" << std::endl;
	// }
}

int createSortedFile(std::string fileName, int* A, int n) {
	std::ofstream sortedFile(fileName);
	if (!sortedFile.is_open()) {
		std::cout << "Error abriendo/creando el archivo" << std::endl;
		return 2;
	}
	for (int i = 0; i < n; i++) {sortedFile << A[i] << std::endl;}
	sortedFile.close();
	return 0;
}

int main(int nargs, char** args) {
	std::string filePath = "../data/" + std::string(args[1]);
	std::vector<int> A = fileReader(filePath);
	int B[A.size()];
	for (int i = 0; i < A.size(); i++) {B[i] = A[i];}

	orderArray(args[2], B, A.size());

	createSortedFile(std::string(args[1]) + ".sorted", B, A.size());

	return 0;
}
