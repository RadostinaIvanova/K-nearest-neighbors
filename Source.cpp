#include <iostream>
#include <vector>
const size_t SIZE = 3;
size_t VALUE = 200;

//calculate distance using the substraction of the income of the uncategorized company and the uncategorized one
//and some given training example plus the result of Hamming distance of the team characterstics of both teams	i.e if the charatestics are the same than is 0 
//if they are not the same then the value is the average of training data income / 3
double calcDist1(std::vector<double> training, std::vector<double> uncategorized) {
	double x = training[0] - uncategorized[0];
	bool y = training[1] == uncategorized[1];
	double d = 0;
	if (y) {
		d = 0;
	}
	else {
		d = VALUE;
	}
	return ab

//calculate distance using those above:
//substracts the income of the some given training example and the uncategorized company
//substracts some given training example characterstics and the uncategorized and then using these as a measurement the following way 
//if they are not the same is 0 and if is something other than d is the result of subtraction multiplied by 100
//the sum of both
double calcDist2(std::vector<double> training, std::vector<double> uncategorized) {
	double x = training[0] - uncategorized[0];
	double y = training[1] - uncategorized[1];
	return abs(x) + abs(y) * 100;
}

//void printVector(std::vector<double> vec) {
//	for (auto it = vec.begin(); it != vec.end(); it++) {
//		std::cout << *it << " "; {}
//	}
//}

void getAllDistances(std::vector<std::vector<double>>  trainingData, std::vector<double> uncategorized) {
	std::pair<double, std::vector<double>> allDistancesAndRows;
	for (auto it = trainingData.begin(); it != trainingData.end(); it++) {

		allDistancesAndRows.first = calcDist1(*it, uncategorized);
		allDistancesAndRows.second = *it;

}
int main() {
	std::vector<double> uncategorized = { 1200, 4, 1 };
	std::vector<std::vector<double>> training = { { 1500, 2, 0 },
												 { 1000, 2, 1 },
												 { 1740, 3, 0 } };
	getAllDistances(training, uncategorized);
	return 0;
}