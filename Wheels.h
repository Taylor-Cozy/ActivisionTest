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
    void CreateWords(vector<string>& possibleWords, string& currentWord, int linesIndex = 0);

protected:
    vector<string> possibleWords;
    Dictionary& dict;
};

