// File: Tax.hpp
// Name: Ram Basnet
// Purpose: Declare the tax input and output functions.

// Guards
#ifndef TAX_HPP
#define TAX_HPP

#include "taxDataType.hpp"

// Precondition: payers points to an array with room for numOfTaxPayers records.
// Postcondition: Each record has valid income, tax rate, and calculated taxes.
void taxTaker(TaxPayer payers[], int numOfTaxPayers);

// Precondition: payers contains numOfTaxPayers completed taxpayer records.
// Postcondition: Information for each taxpayer has been printed.
void taxPrint(const TaxPayer payers[], int numOfTaxPayers);

#endif