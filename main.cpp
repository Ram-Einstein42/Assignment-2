#include <iostream>
#include <iomanip>

// namespace TC
namespace TaxConstants
{
    // for the size of tax payers
    const int SIZE = 4;
}

// struct tax payer
struct TaxPayer
{
    // variables floats
    float income{};
    float taxRate{};
    float taxes{};
};

int main()
{
    TaxPayer payers[TaxConstants::SIZE]{};

    // bool variables
    bool validIncome = false;
    bool validTaxRate = false;

    // setup for the loop
    while (validIncome == false)
    {
        std::cout << "Please enter your income: ";

        if (std::cin >> payers[0].income)
        {
            if (payers[0].income > 0)
            {
                validIncome = true;
            }
            else
            {
                std::cout << "Income must be greater than zero.\n";
            }
        }
        else
        {
            std::cout << "Please enter a number.\n";

            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
    // 2nd setup for loop
    while (validTaxRate == false)
    {
        std::cout << "Please enter your tax rate: ";

        if (std::cin >> payers[0].taxRate)
        {
            if (payers[0].taxRate >= 0.01 && payers[0].taxRate <= 9.9)
            {
                validTaxRate = true;
            }
            else
            {
                std::cout << "Tax rate must be between 0.01 and 9.9.\n";
            }
        }
        else
        {
            std::cout << "Please enter a number.\n";

            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }

    payers[0].taxes = payers[0].income * (payers[0].taxRate / 100);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Accepted Income: $" << payers[0].income << '\n';
    std::cout << "Accepted Tax Rate: " << payers[0].taxRate << '\n';
    std::cout << "Taxes Due: $" << payers[0].taxes << '\n';

    return 0;
}