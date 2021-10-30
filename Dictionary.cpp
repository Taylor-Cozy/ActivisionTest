#include "Dictionary.h"

Dictionary::Dictionary(string filepath) : FileHandler(filepath){
	sort(lines.begin(), lines.end());
}

int Dictionary::BinarySearch(string searchToken, bool (Dictionary::* compare)(string, string))
{
	int lowerBound = 0;
	int upperBound = lines.size() - 1;

	while (true) {
		if (upperBound < lowerBound)
			return -1;

		int midPoint = lowerBound + (upperBound - lowerBound) / 2;
		if ((this->*compare)(lines.at(midPoint), searchToken)) // fnc ptr -> either partial match or full match for word
			return midPoint;
		else {
			int x = searchToken.compare(lines.at(midPoint));
			if (x < 0) {
				upperBound = midPoint - 1;
			}
			if (x > 0) {
				lowerBound = midPoint + 1;
			}
		}
	}
}

void Dictionary::FoundWord(int index)
{
	matches.insert(lines.at(index));
}

void Dictionary::ShowResults() const
{
	for (auto x : matches)
		cout << x << endl;

	cout << "Found " << matches.size() << " words." << endl;
}

bool Dictionary::completeMatch(string left, string right)
{
	if (left == right)
		return true;
	return false;
}

bool Dictionary::partialMatch(string search, string startsWith)
{
	if (search.rfind(startsWith, 0) == 0)
		return true;
	return false;
}
