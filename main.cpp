#include <iostream>
#include <vector>
#include <algorithm> 
#include "KnnAlgorithm.h"
#include "TrainingSet.h"

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
	std::cout << "Input test example: ";
	double income;
	std::string characteristics;
	double successRate = 0;
	std::cin >> income >> characteristics;
	std::vector<double> uncategorized;
	uncategorized.push_back(income);
	uncategorized.push_back(modifyCharacteristics(characteristics));
	uncategorized.push_back(successRate);

	const std::string path = "D:\\FMI\\Github-repos\\K-nearest-neighbors\\DATA.csv";;
	std::vector<std::vector<std::string>> trainingExamplesAsText = getData(path);
	std::vector<std::vector<double>> trainingSet;
	std::vector<double> trainingExample;

	for (std::vector<std::string> line : trainingExamplesAsText) {
		trainingExample.push_back(stod(line[0]));
		trainingExample.push_back(modifyCharacteristics(line[1]));
		trainingExample.push_back(stod(line[2]));
		trainingSet.push_back(trainingExample);
		trainingExample.pop_back();
		trainingExample.pop_back();
		trainingExample.pop_back();
	}

	trainingSet.push_back(uncategorized);
	normalize(trainingSet, 0);
	normalize(trainingSet, 1);
	std::vector<double> test = trainingSet.back();
	trainingSet.pop_back();
	knnClassification(13, trainingSet, test, calcDistWithHamming);
	if (test[2]) {
		std::cout << "Classified as Successful company";
	}
	else {
		std::cout << "Classified as bankrupt company";
	}
	return 0;
}