#include "FileHandler.h"

FileHandler::FileHandler(string filepath) : filepath(filepath)
{

	file.open(filepath);
	if (file.fail()) {
		cout << "Failed to open file." << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		lines.emplace_back(line);
	}
}

FileHandler::~FileHandler()
{
	file.close();
}

