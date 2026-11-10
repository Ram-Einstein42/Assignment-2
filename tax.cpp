// File: Tax.cpp
// Name: Ram Basnet
// Purpose: Implement taxpayer input, validation, calculation, and output.

#include "tax.hpp"
#include "taxConstants.hpp"
#include <iomanip>
#include <iostream>

// Precondition: payers points to an array with room for numOfTaxPayers records.
// Postcondition: Each record has valid income, tax rate, and calculated taxes.
void taxTaker(TaxPayer payers[], int numOfTaxPayers)
{
    // Index of the taxpayer currently being entered.
    int i = 0;

    while (i < numOfTaxPayers)
    {
        // Tracks whether this taxpayer's income is valid.
        bool validIncome = false;

        // Tracks whether this taxpayer's tax rate is valid.
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

        // Calculate taxes using the assignment's stated formula.
        payers[i].taxes = payers[i].income * payers[i].taxRate;
        ++i;
    }
}

// Precondition: payers contains numOfTaxPayers completed taxpayer records.
// Postcondition: Information for each taxpayer has been printed.
void taxPrint(const TaxPayer payers[], int numOfTaxPayers)
{
    // Index of the taxpayer currently being printed.
    int i = 0;

    std::cout << std::fixed << std::setprecision(2);

    while (i < numOfTaxPayers)
    {
        std::cout << "\nTaxpayer #" << i + 1 << '\n';
        std::cout << "Income: $" << payers[i].income << '\n';
        std::cout << "Tax rate: " << payers[i].taxRate << '\n';
        std::cout << "Taxes due: $" << payers[i].taxes << '\n';

        ++i;
    }
}