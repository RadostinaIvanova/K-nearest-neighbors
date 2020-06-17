#include "TrainingSet.h"

//modifies the charachristics of a team by representing them as numbers 
double modifyCharacteristics(std::string& c) {
	if(c == "Very strong"){
		return 4;
	}
	else if (c == "Strong") {
		return 3;
	}
	else if (c == "Average") {
		return 2;
	}
	return 1;
};

std::vector<std::string> split(std::string observation, std::string delim){
	std::vector<std::string> v;
	if (!observation.empty()) {
		size_t start = 0;
		do {
			size_t x = observation.find(delim, start);
			// a check whether target is found
			if (x == -1)
			{
				break;
			}
			std::string tmp = observation.substr(start, x - start);
			v.push_back(tmp);
			start += delim.size() + tmp.size();
		} while (true);

		v.push_back(observation.substr(start));
	}
	return v;
}
std::vector<std::vector<std::string>> getData(const std::string& fileName) {
	std::ifstream file(fileName);
	std::vector<std::vector<std::string>> data;
	std::string line = "";
	while (getline(file, line)) {
		std::vector<std::string> tmp;
		tmp = split(line, ",");
		data.push_back(tmp);
	}
	file.close();
	return data;
}