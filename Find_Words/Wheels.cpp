#include "Wheels.h"

Wheels::Wheels(string filepath, Dictionary& dict) : FileHandler(filepath), dict(dict)
{
	try {
		stoi(lines.front());
	}
	catch (const exception& e) {
		cout << "Invalid Wheels.txt format." << endl;
		exit(1);
	}
	lines.erase(lines.begin(), lines.begin() + 2);
}

void Wheels::GeneratePossibleWords()
{
	string currentWord = "";
	for (int i = 0; i <= lines.size() - 2; i++) {
		CreateWords(currentWord, i);
	}
}

void Wheels::CreateWords(string& currentWord, int linesIndex)
{
	if (linesIndex >= lines.size())
		return;

	int index;

	for (char x : lines.at(linesIndex)) {
		currentWord.push_back(tolower(x));

		index = dict.BinarySearch(currentWord, &Dictionary::partialMatch);
		if (index >= 0) {
			index = dict.BinarySearch(currentWord, &Dictionary::completeMatch);
			if (index >= 0) {
				possibleWords.push_back(dict.GetWord(index));
			}
			CreateWords(currentWord, linesIndex + 1);
		}
		currentWord.pop_back();
	}
}
