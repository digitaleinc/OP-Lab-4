#include "classes.h"

int main()
{
    string num1, num2;
    cout << "Enter the numbers R1 and R2 in separate rows (in arabic or roman)\n";
    cout << "Leave the row empty to set its value to 1 (default)\n";
    getline(cin, num1);
    getline(cin, num2);
    RomanNumeral R1 = createRomanNumeral(num1);
    RomanNumeral R2 = createRomanNumeral(num2);

    cout << "\nR1:\n";
    R1.displayValue();
    cout << "R2:\n";
    R2.displayValue();

    ++R1;
    cout << "\nR1 was incremented:\n";
    R1.displayValue();

    cout << "\nEnter a roman number to add to R2\n";
    string addToR2;
    cin >> addToR2;
    if (isRoman(addToR2))
    {
        R2 += addToR2;
        cout << "\nadded " << addToR2 << " to R2:\n";
        R2.displayValue();
    }
    else
    {
        cout << "\nInvalid value, R2 was not changed\n";
    }

    RomanNumeral R3 = R1 + R2;
    cout << "\nR3 = R1 + R2:\n";
    R3.displayValue();

    return 0;
}
