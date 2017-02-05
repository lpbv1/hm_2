//
// Created by Stephen Clyde on 1/16/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Comparer.h"
#include "Utils.h"
#include "analyst.h"
#include "history.h"
#include "stock.h"

int Comparer::load(int argv, char* argc[])
{
    std::cout << "made it here3" << std::flush;
    if (argv<3)
    {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << "usage: AnalystComparer <output file> <input file 1> <input file 2> ..." << std::endl;
        return -1;
    }

    outputFile = argc[1];
    m_analystCount = argv - 2;
    // TODO: Allocate a container, like an array of pointers, to hold the analysts
    //
    // Example Code:
    analysts.resize(m_analystCount);
    std::cout << "Look here" << std::flush;
    int analystIndex = 0;
    for (int i = 0; i < m_analystCount; i++)
    {
        std::ifstream inputStream(argc[2 + analystIndex]);
        std::string str = (argc[2 + analystIndex]);
        analysts[i].load(inputStream);
        // TODO: Create a new analyst, load it from the input stream, and put it into the container if that load succeeded
        // Example code:
 //       analysts2[analystIndex] = new analyst();
        // if (m_analysts[analystIndex]->load(inputStream) < 0)
        // {
        //     std::cout << "Failed to load " << argc[analystIndex] << std::endl;
        // }
        // else
//        analysts2[analystIndex]->load(inputStream);
        std::cout << "hello" << std::flush;
              analystIndex++;
    }
    std::cout << "made it here also" << std::flush;
    loadSymbols();

    int result = 0;
    if (analystIndex < m_analystCount)
        result = -1;
    std::cout << "made it here2" << std::flush;
    return result;
}

int Comparer::compare() const
{
    std::cout<< "made it here";
    if (m_analystCount < 2)
    {
        std::cout << "Cannot do comparison with " << m_analystCount << " analysts" << std::endl;
        return -1;
    }

    if (outputFile == "")
    {
        std::cout << "Cannot do comparison because no output file is specified" << std::endl;
        return -1;
    }

    std::ofstream outputStream(outputFile);
    outputInvestorNames(outputStream);
    outputOverallPerformance(outputStream);
    outputStockPerformance(outputStream);

    return 0;
}

void Comparer::loadSymbols()
{
    m_symbolsCount = 0;
    int index = 0;
    bool found = false;
    // TODO: Go through all analysts' histories and build a list of symbols used in any Purchase-Sale.
    for (int x = 0; x < analysts.size(); x++){
        for (int y = 0; y < analysts[x].getHistory().getStock().size(); y++){
            std::string name = analysts[x].getHistory().getStock()[y].getName();
            for (int z = 0; z < m_symbols->size(); z++){
                if (name == m_symbols[z]){
                    found = true;
                }
            }
            if (!found){
                m_symbols[index] = name;
                index++;
                found = false;
            }
        }
    }
    // According to the design, every analyst has a design and a history contains purchase-sale objects.
    // Each purchase-sale object is for a symbol.
    //
    // The m_symbols array contains the list of references symbols.  The std::find methods checks to see
    // if a symbol is already in that array.  If it is not, then the result result is the std::end of the
    // the array and the symbol is array to the array.
    //
    // Example code:
    // for (int i = 0; i < m_analystCount; i++)
    // {
    //    History& history = m_analysts[i]->getHistory();
    //    history.resetIterator();
    //    const PurchaseSale* purchaseSale;
    //    while ((purchaseSale = history.nextPurchaseSale()) != nullptr)
    //    {
    //        std::string symbol = purchaseSale->getSymbol();
    //        std::string *existingSymbol = std::find(std::begin(m_symbols), std::end(m_symbols), symbol);
    //        if (existingSymbol == std::end(m_symbols)) {
    //            m_symbols[m_symbolsCount++] = symbol;
    //        }
    //    }
    // }
}


void Comparer::outputInvestorNames(std::ofstream& outputStream) const
{
    // TODO: Write out investor names
    outputStream << "Analyst Comparison" << std::endl << std::endl << "Investors:" << std::endl;
    for (int x = 0; x < analysts.size(); x++){
        outputStream << analysts[x].getInitials() << ": " << analysts[x].getName() << std::endl;
    }
}

void Comparer::outputOverallPerformance(std::ofstream& outputStream) const
{
    // TODO: Write out Overall Performance table.  The classes from the FormattedTable example might be helpful.
};

void Comparer::outputStockPerformance(std::ofstream& outputStream) const
{
    // TODO: Write out Stock Performance table.  The classes from the FormattedTable example might be helpful.
}
