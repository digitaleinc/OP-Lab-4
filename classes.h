#include "functions.h"
class RomanNumeral
{
private:
    int arabic;
    string roman;
public:
    RomanNumeral();
    RomanNumeral(int arabic);
    RomanNumeral(string roman);

    void displayValue();
    RomanNumeral operator+(RomanNumeral other);
    RomanNumeral& operator++();
    RomanNumeral operator++(int);
    RomanNumeral& operator+=(string roman);
};

RomanNumeral createRomanNumeral(string input);