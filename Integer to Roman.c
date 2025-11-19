#include <stdio.h>
#include <string.h>

char* intToRoman(int num) {
    // Predefined Roman numerals and their values
    int values[] =    {1000, 900, 500, 400, 100, 90,  50,  40,  10, 9,   5,  4, 1};
    char* symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    // Output string buffer (max length for Roman numeral < 20 for numbers <= 3999)
    static char result[20];
    result[0] = '\0'; // initialize as empty string

    for(int i = 0; i < 13; i++) {
        while(num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}

