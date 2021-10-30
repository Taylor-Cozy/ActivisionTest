#pragma once
#include "FileHandler.h"

class Dictionary :
    public FileHandler
{
public:
    Dictionary(string filepath);
    virtual ~Dictionary() {};

    int BinarySearch(string searchToken, bool (Dictionary::* compare)(string, string));

    void FoundWord(int index);

    int GetCount() const { return count; };

    void ShowResults() const;

    bool completeMatch(string left, string right);
    bool partialMatch(string left, string right);

protected:
    int maximumLength = 4;
    int count = 0;
    set<string> matches;
};

