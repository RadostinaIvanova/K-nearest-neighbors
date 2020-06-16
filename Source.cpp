#include <iostream>
const size_t SIZE = 3;
size_t VALUE = 200;

//calculate distance using the substraction of the income of the uncategorized company and the uncategorized one
//and some given training example plus the result of Hamming distance of the team characterstics of both teams	i.e if the charatestics are the same than is 0 
//if they are not the same then the value is the average of training data income / 3

double calcDist1(double training[], double uncategorized[]) {
	double x = training[0] - uncategorized[0];
	bool y = training[1] == uncategorized[1];
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
//substracts the income of the some given training example and the uncategorized company
//substracts some given training example characterstics and the uncategorized and then using these as a measurement the following way 
//if they are not the same is 0 and if is something other than d is the result of subtraction multiplied by 100
//the sum of both
double calcDist1(double training[], double uncategorized[]) {
	double x = training[0] - uncategorized[0];
	int y = training[1] - uncategorized[1];
	double d = 0;
	return abs(x) + d * 100;
}
int main() {
	double training[SIZE] = { 1000, 3, 0 };
	double uncategorized[SIZE] = { 1200, 4, 1 };
	std::cout << calcDist1(training, uncategorized);
	return 0;
}