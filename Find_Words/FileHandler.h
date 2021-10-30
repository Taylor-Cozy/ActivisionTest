#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class FileHandler
{
public:
	FileHandler(string) throw (invalid_argument);
	virtual ~FileHandler();

protected:
	string filepath;
	ifstream file;
	vector<string> lines;
};

