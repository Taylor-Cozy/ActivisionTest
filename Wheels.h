#pragma once
#include "FileHandler.h"
#include "Dictionary.h"

class Wheels :
    public FileHandler
{
public:
    Wheels(string filepath, Dictionary& dict);
    virtual ~Wheels() {};

    void GeneratePossibleWords();
    int GetWheelCount() const { return wheelCount; };
    void CreateWords(vector<string>& possibleWords, string& currentWord, int linesIndex = 0);

protected:
    int wheelCount;
    vector<string> possibleWords;
    Dictionary& dict;
};

