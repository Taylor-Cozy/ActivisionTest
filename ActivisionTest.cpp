#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "FileHandler.h"
#include "Dictionary.h"
#include "Wheels.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 1) {
        cout << "Usage: find_words.exe Dictionary.txt Wheels.txt";
        exit(1);
    }

    auto t1 = chrono::high_resolution_clock::now();
    Dictionary dictionary(argv[1]);
    auto t2 = chrono::high_resolution_clock::now();
    Wheels wheels(argv[2], dictionary);
    auto t3 = chrono::high_resolution_clock::now();
    wheels.GeneratePossibleWords();
    auto t4 = chrono::high_resolution_clock::now();

    dictionary.ShowResults();

#if _DEBUG
    chrono::duration<double, std::milli> dictLoad = t2 - t1;
    chrono::duration<double, std::milli> wheelsLoad = t3 - t2;
    chrono::duration<double, std::milli> generate = t4 - t3;
    chrono::duration<double, std::milli> total = t4 - t1;

    cout << "Loaded Dictionary.txt in\t" << dictLoad.count() << "ms" << endl;
    cout << "Loaded Wheels.txt in\t\t" << wheelsLoad.count() << "ms" << endl;
    cout << "Generated Words in\t\t" << generate.count() << "ms" << endl;
    cout << "Total Time Taken: \t\t" << total.count() << "ms" << endl;
#endif
}