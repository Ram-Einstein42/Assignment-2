// File: taxDataType.hpp
// Name: Ram Basnet
// Purpose: Define the data stored for each taxpayer.

// Guards
#ifndef TAXDATATYPE_HPP
#define TAXDATATYPE_HPP

// Stores one taxpayer's income, tax rate, and taxes due.
struct TaxPayer
{
    float income;
    float taxRate;
    float taxes;
};

#endif