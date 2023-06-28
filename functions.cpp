#include "functions.h"

bool isNumber(string str)
{
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool isRoman(string str)
{
    string validRomanDigits = "IVXLCDM";
    for (char c : str)
    {
        if (validRomanDigits.find(c) == string::npos)
            return false;
    }
    return true;
}

string toRoman(int arabic)
{
    string res = "";
    const string RD[4][10] =
            {
                    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                    {"", "M", "MM", "MMM"}
            };

    int power10 = 0;
    while (arabic > 0)
    {
        int digit = arabic % 10;
        switch (power10)
        {
            case 0:
                res = RD[power10][digit] + res;
                break;
            case 1:
                res = RD[power10][digit] + res;
                break;
            case 2:
                res = RD[power10][digit] + res;
                break;
            case 3:
                res = RD[power10][digit] + res;
                break;
        }
        arabic /= 10;
        power10 += 1;
    }
    return res;
}

int toArabic(string roman)
{
    int res = 0;
    string CorrToAD[3][10] =
            {   {"\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"\0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"\0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
            };

    for (int i = 0; i < 3; i++)
    {
        size_t posOf9 = roman.find(CorrToAD[i][9]);
        if (posOf9 != string::npos)
        {
            roman.substr(posOf9, 2);
            res += 9 * pow(10, i);
        }

        size_t posOf4 = roman.find(CorrToAD[i][4]);
        if (posOf4 != string::npos)
        {
            roman.substr(posOf4, 2);
            res += 4 * pow(10, i);
        }

        size_t posOf1 = roman.find(CorrToAD[i][1]);
        if (posOf1 != string::npos)
        {
            roman.substr(posOf1, 1);
            res += roman.length() * pow(10, i);
        }

        size_t posOf5 = roman.find(CorrToAD[i][5]);
        if (posOf5 != string::npos)
        {
            roman.substr(posOf5, 1);
            res += 5 * round(pow(10, i));
        }
    }
    return res;
}
