#pragma once
#include "FileHandler.h"
#include <set>
#include <algorithm>

class Dictionary :
    public FileHandler
{
public:
    Dictionary(string filepath);
    virtual ~Dictionary() {};

    int BinarySearch(string searchToken, bool (Dictionary::* compare)(string, string));

    void FoundWord(int index);
    void ShowResults() const;
    bool completeMatch(string left, string right);
    bool partialMatch(string left, string right);

protected:
    set<string> matches;
};

