#include <string>
#include <iostream>
#include "headers/romanos.hpp"

using namespace std;

RomanNumerals RomanNumbers::GetRomanNumeralFromChar(char numeral) {
    switch (numeral)
    {
    case 'I':
        return I;
        break;
    case 'V':
        return V;
        break;
    case 'X':
        return X;
        break;
    case 'L':
        return L;
        break;
    case 'C':
        return C;
        break;
    case 'D':
        return D;
        break;
    case 'M':
        return M;
        break;
    default:
        return Unknown;
        break;
    }
}

bool RomanNumbers::ValidateRomanNumber(string romanNumber) {
    if(romanNumber.length() > 30) {
        return false;
    }

    for(int i = 0; i < romanNumber.length(); i++) {
        if(GetRomanNumeralFromChar(romanNumber[i])==Unknown) {
            return false;
        }
    }

    return true;
}

int RomanNumbers::recursiveGetValue(RomanNumerals lastNumeral, string remainingNumerals, int value) {
    if(remainingNumerals.length()==0) {
        return value;
    }

    string numerals = remainingNumerals;

    RomanNumerals nextNumeral = GetRomanNumeralFromChar(numerals[numerals.length()-1]);
    numerals.pop_back();

    if(nextNumeral < lastNumeral) {
        return recursiveGetValue(lastNumeral, numerals, value - nextNumeral);
    } else {
        return recursiveGetValue(nextNumeral, numerals, value + nextNumeral);   
    }
}

int RomanNumbers::GetValue(string romanNumber) {
    if(!RomanNumbers::ValidateRomanNumber(romanNumber)) {
        return -1;
    }

    return recursiveGetValue(Unknown, romanNumber, 0);
}
