#include <iostream>
#include "taxConstants.hpp"
#include "taxDataType.hpp"
#include "tax.hpp"


int main()
{
    // Create an array that can hold up to four taxpayers.
    TaxPayer payers[TaxConstants::SIZE]{};
    int numOfTaxPayers{};
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
                std::cin.ignore(1000, '\n');
            }
        }
        else
        {
            std::cout << "Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    // Call the functions to get, calculate, and print taxpayer information.
    taxTaker(payers, numOfTaxPayers);
    taxPrint(payers, numOfTaxPayers);

    return 0;
}