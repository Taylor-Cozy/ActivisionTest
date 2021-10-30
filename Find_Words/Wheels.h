#pragma once

#include "FileHandler.h"
#include "Dictionary.h"

class Wheels : public FileHandler
{
public:
    Wheels(string filepath, Dictionary& dict);
    virtual ~Wheels() {};

    void GeneratePossibleWords();
    void CreateWords(string& currentWord, int linesIndex = 0);

    void ShowResults() const {
        for (auto x : possibleWords)
            cout << x << endl;
        cout << "Found " << possibleWords.size() << " words." << endl;
    }

protected:
    vector<string> possibleWords;
    Dictionary& dict;
};

