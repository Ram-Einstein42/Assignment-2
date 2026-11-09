#include <iostream>
#include <iomanip>
int main()
{
    float income{};
    float taxRate{};
    float taxes {};
    bool validIncome = false;
    bool validTaxRate = false;

    while (validIncome == false)
    {
        std::cout << "Please enter your income: ";

        if (std::cin >> income)
        {
            if (income > 0)
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
    while (validTaxRate == false)
    {
        std::cout << "Please enter your tax rate: ";
        if (std::cin >> taxRate)
        {
            if (taxRate >= 0.01 && taxRate <= 9.9)
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
    taxes = income * (taxRate / 100);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Accepted Income: $" << income << '\n';
    std::cout << "Accepted Tax: " << taxRate << '\n';
    std::cout << "Taxed: $" << taxes<< '\n';

    return 0;
}