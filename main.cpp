// File: main.cpp
// Name: Your Name
// Purpose: Collect the number of taxpayers and run the tax program.

#include <iostream>
#include "taxConstants.hpp"
#include "taxDataType.hpp"
#include "tax.hpp"

// Precondition: The tax functions are declared in tax.hpp.
// Postcondition: Taxpayer information has been entered, calculated, and printed.
int main()
{
    // Array that stores up to SIZE taxpayer records.
    TaxPayer payers[TaxConstants::SIZE]{};

    // Number of taxpayer records the user wants to enter.
    int numOfTaxPayers{};

    // Tracks whether the taxpayer count is valid.
    bool validPayerCount = false;

    // Ask how many taxpayer records the user wants to enter.
    while (validPayerCount == false)
    {
        std::cout << "How many taxpayers? Enter 1 through "
                  << TaxConstants::SIZE << ": ";

        if (std::cin >> numOfTaxPayers)
        {
            if (numOfTaxPayers >= 1 &&
                numOfTaxPayers <= TaxConstants::SIZE)
            {
                validPayerCount = true;
            }
            else
            {
                std::cout << "Enter a number from 1 through "
                          << TaxConstants::SIZE << ".\n";
                std::cin.ignore(TaxConstants::INPUT_LINE_LENGTH, '\n');
            }
        }
        else
        {
            std::cout << "Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(TaxConstants::INPUT_LINE_LENGTH, '\n');
        }
    }

    // Get, calculate, and print taxpayer information.
    taxTaker(payers, numOfTaxPayers);
    taxPrint(payers, numOfTaxPayers);

    return 0;
}