#include "classes.h"

RomanNumeral::RomanNumeral()
{
    arabic = 1;
    roman = toRoman(arabic);
}

RomanNumeral::RomanNumeral(int arabicValue)
{
    arabic = arabicValue;
    roman = toRoman(arabic);
}

RomanNumeral::RomanNumeral(string romanValue)
{
    roman = romanValue;
    arabic = toArabic(roman);
}

void RomanNumeral::displayValue()
{
    cout << "Arabic: " << arabic << endl;
    cout << "Roman: " << roman << endl;
}

RomanNumeral RomanNumeral::operator+(RomanNumeral other)
{
    int result = arabic + other.arabic;
    return RomanNumeral(result);
}

RomanNumeral& RomanNumeral::operator++()
{
    arabic++;
    roman = toRoman(arabic);
    return *this;
}

RomanNumeral RomanNumeral::operator++(int)
{
    RomanNumeral temp = *this;
    ++(*this);
    return temp;
}

RomanNumeral& RomanNumeral::operator+=(string romanValue)
{
    int addValue = toArabic(romanValue);
    arabic += addValue;
    roman = toRoman(arabic);
    return *this;
}

RomanNumeral createRomanNumeral(string input)
{
    RomanNumeral R;
    if (isNumber(input))
    {
        int value = stoi(input);
        R = RomanNumeral(value);
    }
    else if (isRoman(input))
    {
        R = RomanNumeral(input);
    }
    else
    {
        R = RomanNumeral();
    }
    return R;
}