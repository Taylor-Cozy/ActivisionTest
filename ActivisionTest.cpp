#include <iostream>
#include <fstream>
#include <string>
#include "FileHandler.h"
#include "Dictionary.h"
#include "Wheels.h"
#include <chrono>
using namespace std;



int main(int argc, char* argv[])
{
    cout << "You have entered " << argc << " parameters: " << endl;
    for (int x = 0; x < argc; x++) {
        cout << argv[x] << endl;
    }

    auto t1 = chrono::high_resolution_clock::now();
    Dictionary dictionary("dictionary.txt");
    auto t2 = chrono::high_resolution_clock::now();
    Wheels wheels("wheels.txt", dictionary);
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