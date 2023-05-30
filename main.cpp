#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sys/time.h>
#include "containers/vector.hpp"
#include <vector>
// #define RNG    10000 + (std::rand() % 50000)

template <typename T>
void printVectorInfo(ft::vector<T> &vector) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "vector::empty() = " << vector.empty() << std::endl
	          << "vector::size() = " << vector.size() << std::endl
	        //   << "vector::max_size() = " << vector.max_size() << std::endl
	          << "Contents:" << std::endl;
}

template <typename T>
void printVectorInfo(std::vector<T> &vector) {
	std::cout << "--------------------------------------------------" << std::endl << std::boolalpha
	          << "vector::empty() = " << vector.empty() << std::endl
	          << "vector::size() = " << vector.size() << std::endl
	        //   << "vector::max_size() = " << vector.max_size() << std::endl
	          << "Contents:" << std::endl;
}

template <typename T>
void printByOperator(ft::vector<T> &vector) {
	printVectorInfo(vector);
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << "vector[" << i << "] = " << vector[i] << std::endl;
	}
}

template <typename T>
void printByOperator(std::vector<T> &vector) {
	printVectorInfo(vector);
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << "vector[" << i << "] = " << vector[i] << std::endl;
	}
}

void rangeInsert(ft::vector<std::string> &vector);
void rangeInsert2(std::vector<std::string> &vector);

int main() {


	{
		ft::vector<std::string> test;
		std::vector<std::string> test2;
		rangeInsert(test);
		rangeInsert2(test2);
		printByOperator(test);
		printByOperator(test2);

	}
	return 0;
}

void rangeInsert(ft::vector<std::string> &vector) {
	vector.insert(vector.begin(), 3, "My");
	vector.insert(vector.begin() + (vector.size() / 2), 5, "dentist");
	vector.insert(vector.begin() + (vector.size() / 3), 0, "tells");
	vector.insert(vector.begin() + (vector.size() / 4), 4, "me");
	vector.insert(vector.begin() + (vector.size() / 5), 1, "that");
	vector.insert(vector.begin() + (vector.size() - 1), 10, "chewing");
	vector.insert(vector.end() - 1, 1, "bricks");
	vector.insert(vector.end() - vector.size(), 5, "is very bad");
	vector.insert(vector.end() - (vector.size() / 2), 0, "for your");
	vector.insert(vector.end() - (vector.size() / 3), 8, "teeth");
	vector.insert(vector.end() - (vector.size() / 4), 2, "😬");
}

void rangeInsert2(std::vector<std::string> &vector) {
	vector.insert(vector.begin(), 3, "My");
	vector.insert(vector.begin() + (vector.size() / 2), 5, "dentist");
	vector.insert(vector.begin() + (vector.size() / 3), 0, "tells");
	vector.insert(vector.begin() + (vector.size() / 4), 4, "me");
	vector.insert(vector.begin() + (vector.size() / 5), 1, "that");
	vector.insert(vector.begin() + (vector.size() - 1), 10, "chewing");
	vector.insert(vector.end() - 1, 1, "bricks");
	vector.insert(vector.end() - vector.size(), 5, "is very bad");
	vector.insert(vector.end() - (vector.size() / 2), 0, "for your");
	vector.insert(vector.end() - (vector.size() / 3), 8, "teeth");
	vector.insert(vector.end() - (vector.size() / 4), 2, "😬");
}
