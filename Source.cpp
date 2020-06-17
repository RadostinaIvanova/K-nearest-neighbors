#include <iostream>
#include <vector>
#include <algorithm> 

const size_t SIZE = 3;
const int successRate = 2;

//a pair with first member represents the distance from the test  
using closenessPair = std::pair<double, std::vector<double>>;

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

//calculate distance using the substraction of the income of the test tuple and a observation one
//and some given training example plus the result of Hamming distance of the team characterstics of both teams	i.e if the charatestics are the same than is 0 
//if they are not the same then the value is 1
double calcDist1(std::vector<double> observation, std::vector<double> test) {
	double x = observation[0] - test[0];
	bool y = observation[1] == test[1];
	double d = 0;
	if (y) {
		d = 0;
	}
	else {
		d = 1;
	}
	return abs(x) + d;
}

//calculate distance using those above:
//substracts the income of the some given observation i.e training example and the test tuple
//substracts some given observation characterstics and the test tuple 
//using euclidean formula
double calcDist2(std::vector<double> observation, std::vector<double> test) {
	double x = observation[0] - test[0];
	double y = observation[1] - test[1];
	return sqrt(pow(abs(x), 2) + pow(abs(y), 2));
}

bool sortByFst(const closenessPair& a,
	const closenessPair& b) {
	return (a.first < b.first);
};


std::vector<closenessPair> findKNN(size_t k,
	std::vector<std::vector<double>>  trainingSet,
	std::vector<double> test,
	double calFunc(std::vector<double>, std::vector<double>))
{
	std::vector<closenessPair> allDistAndObs;
	for (auto it = trainingSet.begin(); it != trainingSet.end(); it++) { //caluclates all distances from the test to some example of the training set making a pair of it 
		closenessPair distAndObservation;							     // the pair first member is the distance itself and the second parameter is the observation tuple
		distAndObservation.first = calFunc(*it, test);					//after all that puts those pairs in a vector
		distAndObservation.second = *it;
		allDistAndObs.push_back(distAndObservation);
	}
	std::sort(allDistAndObs.begin(), allDistAndObs.end(), sortByFst);   //sorts the pairs
	std::vector<closenessPair> knn(allDistAndObs.begin(), allDistAndObs.begin() + k);  //making new vector but only with k of the elements of the first which repesentes										  //the k nearest neighbours and their distances from the test tuple
	return knn;
}


//counts 
void knnClassification(size_t k,
	std::vector<std::vector<double>> trainingSet,
	std::vector<double>& test,
	double calFunc(std::vector<double>, std::vector<double>))
{
	int bankruptcyCnt = 0;
	int successCnt = 0;
	std::vector<closenessPair> knn = findKNN(k, trainingSet, test, calFunc);
	printVecOfPairs(knn);
	for (auto it = knn.begin(); it != knn.end(); it++) {
		double bs = it->second[successRate];
		if (bs) {
			successCnt++;
		}
		else {
			bankruptcyCnt++;
		}
	}
	if (bankruptcyCnt > successCnt) {
		test[successRate] = 0;
	}
	else if (successCnt > bankruptcyCnt) {
		test[successRate] = 1;
	}
	else {
		test[successRate] = knn.begin()->second[2];
	}
}

void findMinMax(std::vector<std::vector<double>> training, double& min, double& max, size_t category) {
	size_t minInd = 0;
	size_t maxInd = 0;
	for (size_t i = 1; i < training.size(); i++) {
		if (training[minInd][category] < training[i][category]) {
			minInd = i;
		}
		if (training[maxInd][category] > training[i][category]) {
			maxInd = i;
		}
	}
	min = training[minInd][category];
	max = training[maxInd][category];
}

//normalise categories with the following formula: current value - min value of the column/ max value - min value
void normalise(std::vector<std::vector<double>>& trainingSet, size_t category) {
	double min;
	double max;
	findMinMax(trainingSet, min, max, category);
	for (auto it = trainingSet.begin(); it != trainingSet.end(); it++) {
		(*it)[category] = ((*it)[category] - min) / (max - min);
	}
}
int main() {
	std::vector<double> uncategorized = { 1200, 4, 1 };
	std::vector<std::vector<double>> training = { { 1200, 4, 0 } ,
												 { 1500, 2, 0 },
												 { 1000, 4, 1 },
												 { 1740, 3, 0 },
												 { 1240, 1, 1} };
	normalise(training, 0);
	normalise(training, 1);
	std::vector<double> test = training.back();
	training.pop_back();
	knnClassification(3, training, test, calcDist2);
	printVector(test);
	return 0;
}