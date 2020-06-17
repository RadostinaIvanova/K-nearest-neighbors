#ifndef _TRAININGSET_H
#define _TRAININGSET_H
#include <fstream>
#include <string>
#include "KnnAlgorithm.h"

std::vector<std::string> split(std::string observation, std::string delim);

std::vector<std::vector<std::string>> getData(const std::string&);

double modifyCharacteristics(std::string& c);

#endif // !_TRAININGSET_H

