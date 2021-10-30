#include "Wheels.h"

Wheels::Wheels(string filepath, Dictionary& dict) : FileHandler(filepath), dict(dict)
{
	wheelCount = lines.size() - 2; // Could also use stoi(lines.at(0))
	lines.erase(lines.begin(), lines.begin() + 2);
}

void Wheels::GeneratePossibleWords()
{
	string currentWord = "";
	for (int i = 0; i <= lines.size() - 2; i++) {
		CreateWords(possibleWords, currentWord, i);
	}
}

void Wheels::CreateWords(vector<string>& possibleWords, string& currentWord, int linesIndex)
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
				dict.FoundWord(index);
			}
			CreateWords(possibleWords, currentWord, linesIndex+1);
		}
		currentWord.pop_back();
	}
}
