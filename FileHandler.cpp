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

	string line;
	while (getline(file, line)) {
		lines.emplace_back(line);
	}
}

FileHandler::~FileHandler()
{
	file.close();
}

