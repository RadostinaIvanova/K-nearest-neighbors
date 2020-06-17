#include <iostream>
#include <vector>
#include <algorithm> 

const size_t SIZE = 3;
size_t VALUE = 200;

//a pair with first member represents the distance from the test  
using closenessPair = std::pair<double, std::vector<double>>;

//calculate distance using the substraction of the income of the test tuple and a observation one
//and some given training example plus the result of Hamming distance of the team characterstics of both teams	i.e if the charatestics are the same than is 0 
//if they are not the same then the value is the average of training data income / 3

double calcDist1(std::vector<double> observation, std::vector<double> test) {
	double x = observation[0] - test[0];
	bool y = observation[1] == test[1];
	double d = 0;
	if (y) {
		d = 0;
	}
	else {
		d = VALUE;
	}
	return abs(x) + d;
}

//calculate distance using those above:
//substracts the income of the some given observation i.e training example and the test tuple
//substracts some given observation characterstics and the test tuple and then using these as a measurement the following way 
//if they are not the same is 0 and if is something other than d is the result of subtraction multiplied by 100
//the sum of both
double calcDist2(std::vector<double> observation, std::vector<double> test) {
	double x = observation[0] - test[0];
	double y = observation[1] - test[1];
	return abs(x) + abs(y) * 100;
}

bool sortByFst(const closenessPair& a,
	const closenessPair& b) {
	return (a.first < b.first);
};

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
std::vector<double> knnClassification(size_t k,
	std::vector<std::vector<double>> trainingSet,
	std::vector<double> test,
	double calFunc(std::vector<double>, std::vector<double>))
{
	int bankruptcyCnt = 0;
	int successCnt = 0;
	std::vector<closenessPair> knn = findKNN(k, trainingSet, test, calFunc);
	printVecOfPairs(knn);
	for (auto it = knn.begin(); it != knn.end(); it++) {
		double bs = it->second[2];
		if (bs) {
			successCnt++;
		}
		else {
			bankruptcyCnt++;
		}
	}
	if (bankruptcyCnt > successCnt) {
		test[2] = 0;
	}
	else if (successCnt > bankruptcyCnt) {
		test[2] = 1;
	}
	else {
		test[2] = knn.begin()->second[2];
	}
	return test;
}

int main() {
	std::vector<double> uncategorized = { 1200, 4, 1 };
	std::vector<std::vector<double>> training = { { 1500, 2, 0 },
												 { 1000, 4, 1 },
												 { 1740, 3, 0 },
												 { 1240, 1, 1} };
	std::vector<double> testTuple = knnClassification(4, training, uncategorized, calcDist1);
	printVector(testTuple);
	return 0;
}