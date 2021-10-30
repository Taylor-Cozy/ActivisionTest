#include "FileHandler.h"

FileHandler::FileHandler(string filepath) throw (invalid_argument) : filepath(filepath)
{
	try {
		file.open(filepath);
		if (file.fail()) {
			throw invalid_argument("No file exists " + filepath);
		}
		if (file.peek() == ifstream::traits_type::eof()) {
			throw runtime_error("File cannot be empty.");
		}
	}
	catch (const invalid_argument& iae) {
		cout << iae.what() << "\n";
		exit(1);
	}
	catch (const runtime_error& rte) {
		cout << rte.what() << "\n";
		exit(1);
	}
	catch (...) {
		cout << "Could not open file." << endl;
		exit(1);
	}

	// Limit number of vector re-assignments by reserving memory first
	file.seekg(0, ios::end);
	size_t lineCount = file.tellg();
	lines.reserve(lineCount / 5); // Average length of a word in English is 5 characters

	file.clear();
	file.seekg(ios::beg);

	string line;
	while (getline(file, line)) {
		lines.push_back(line);
	}
}

FileHandler::~FileHandler()
{
	file.close();
}

