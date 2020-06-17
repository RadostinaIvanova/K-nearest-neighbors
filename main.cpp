#include <iostream>
#include <vector>
#include <algorithm> 
#include "KnnAlgorithm.h"

void printVector(std::vector<double> vec) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " "; {}
	}
}

void printPairs(closenessPair p) {
	std::cout << p.first << " ; ";
	printVector(p.second);
	std::cout << std::endl;
}

void printVecOfPairs(std::vector<closenessPair> vec) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		printPairs(*it);
	}
}

int main() {
	std::vector<double> uncategorized = { 1200, 4, 1 };
	std::vector<std::vector<double>> training = { { 1200, 4, 0 } ,
												 { 1500, 2, 0 },
												 { 1000, 4, 1 },
												 { 1740, 3, 0 },
												 { 1240, 1, 1}};
	normalise(training, 0);
	normalise(training, 1);
	std::vector<double> test = training.back();
	training.pop_back();
	knnClassification(3, training, test, calcDist2);
	printVector(test);
	return 0;
}