// Copyright 2021 titosilva

#ifndef HEADERS_ROMANOS_HPP_
#define HEADERS_ROMANOS_HPP_
#include <string>

using std::string;

enum RomanNumerals {
    Unknown = 0,
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000,
};

class RomanNumbers {
 public:
     static bool ValidateRomanNumber(string romanNumber);
     static RomanNumerals GetRomanNumeralFromChar(char numeral);
     static int GetValue(string romanNumber);
 private:
     static int recursiveGetValue(RomanNumerals, string, int);
};

#endif  // HEADERS_ROMANOS_HPP_
