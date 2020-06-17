#ifndef _KNNALGORITHM_
#define _KNNALGORITHM_
#include <iostream>
#include <vector>
#include <algorithm> 

const size_t SIZE = 3;
const int successRate = 2;
//a pair with first member represents the distance from the test  
using closenessPair = std::pair<double, std::vector<double>>;

double calcDist1(std::vector<double> observation, std::vector<double> test);

double calcDist2(std::vector<double> observation, std::vector<double> test);

bool sortByFst(const closenessPair& a, const closenessPair& b);

std::vector<closenessPair> findKNN(size_t k,
								  std::vector<std::vector<double>>  trainingSet,
								  std::vector<double> test,
								  double calFunc(std::vector<double>, std::vector<double>));
void knnClassification(size_t k,
	std::vector<std::vector<double>> trainingSet,
	std::vector<double>& test,
	double calFunc(std::vector<double>, std::vector<double>));

void findMinMax(std::vector<std::vector<double>> training, double& min, double& max, size_t category);

void normalise(std::vector<std::vector<double>>& trainingSet, size_t category);

#endif 


