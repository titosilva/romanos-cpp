#ifndef ROMANOS_HPP_
#define ROMANOS_HPP_
#include <string>

using namespace std;

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
    static int recursiveGetValue(RomanNumerals lastNumeral, string remainingNumerals, int value);
};

#endif