// Include the function prototypes and required libraries
#include "tax.hpp"
#include <iomanip>
#include <iostream>

// Get and validate each taxpayer's information, then calculate taxes.
void taxTaker(TaxPayer payers[], int numOfTaxPayers)
{
    for (int i = 0; i < numOfTaxPayers; ++i)
    {
        bool validIncome = false;
        bool validTaxRate = false;

        while (validIncome == false)
        {
            std::cout << "Please enter the income for taxpayer "
                      << i + 1 << ": ";

            if (std::cin >> payers[i].income)
            {
                if (payers[i].income > 0)
                {
                    validIncome = true;
                }
                else
                {
                    std::cout << "Income must be greater than zero.\n";
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

        while (validTaxRate == false)
        {
            std::cout << "Please enter the tax rate for taxpayer "
                      << i + 1 << " (0.01 through 9.9): ";

            if (std::cin >> payers[i].taxRate)
            {
                if (payers[i].taxRate >= 0.01 &&
                    payers[i].taxRate <= 9.9)
                {
                    validTaxRate = true;
                }
                else
                {
                    std::cout << "Tax rate must be between 0.01 and 9.9.\n";
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

        // Calculate taxes using the assignment's formula.
        payers[i].taxes = payers[i].income * payers[i].taxRate;
    }
}

// Print each taxpayer's information.
void taxPrint(const TaxPayer payers[], int numOfTaxPayers)
{
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < numOfTaxPayers; ++i)
    {
        std::cout << "\nTaxpayer #" << i + 1 << '\n';
        std::cout << "Income: $" << payers[i].income << '\n';
        std::cout << "Tax rate: " << payers[i].taxRate << '\n';
        std::cout << "Taxes due: $" << payers[i].taxes << '\n';
    }
}