#include <iostream>
const size_t SIZE = 3;
size_t VALUE = 200;
//calculate distance using the difference of income of the uncategorized company minus and some given training example
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

int main() {
	double training[SIZE] = { 1000, 3, 0 };
	double uncategorized[SIZE] = { 1200, 4, 1 };
	std::cout << calcDist1(training, uncategorized);
	return 0;
}