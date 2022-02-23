#pragma once

#include "FileHandler.h"
#include <set>
#include <algorithm>

class Dictionary : public FileHandler
{
public:
    Dictionary(string filepath);
    virtual ~Dictionary() {};

    int BinarySearch(string searchToken, bool (Dictionary::* compare)(string, string) const);

    void FoundWord(int index) {
        matches.push_back(lines.at(index));
    };
    void ShowResults() const;

    bool completeMatch(string left, string right) const {
        return left == right ? true : false;
    };
    bool partialMatch(string left, string right) const {
        return left.rfind(right, 0) == 0 ? true : false;
    };

    string GetWord(int index) const {
        return lines[index];
    }

protected:
    vector<string> matches;
};

