#pragma once

#include <fstream>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

class FileHandler
{
public:
	FileHandler(string);
	virtual ~FileHandler();



protected:
	string filepath;
	ifstream file;
	vector<string> lines;
};

