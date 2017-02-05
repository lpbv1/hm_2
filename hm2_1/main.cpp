#include "Comparer.h"
#include <iostream>
int main(int argv, char* argc[])
{
    std::cout << "made it here5" << std::flush;
    // Declare (and create) a comparer object
    Comparer comparer;
    std::cout << "made it here4" << std::flush;
    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    if (comparer.load(argv, argc)==0)
        comparer.compare();
}