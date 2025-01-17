
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int symbolToValue(char c) {

    switch(c) {
        case 'I': 
            return 1;
        case 'V': 
            return 5;
        case 'X': 
            return 10;
        case 'L': 
            return 50;
        case 'C': 
            return 100;
        case 'D': 
            return 500;
        case 'M': 
            return 1000;
        default: 
            return 0;
    }
}


int romanToInt(char* s) {

    int sum = 0;

    for (int i = 0; i < strlen(s); i++) {
        int val = symbolToValue(s[i]);
        if (val < symbolToValue(s[i + 1])) {
            sum -= val;
        } else {
            sum += val;
        }
    }

    return sum;
}


int main() {
    // Test cases.
    char *romanNumerals[] = {
        "III",      // 3
        "LVIII",    // 58
        "MCMXCIV",  // 1994
    };

    int size = sizeof(romanNumerals) / sizeof(romanNumerals[0]);

    for (int i = 0; i < size; i++) {
        printf("Case #%d: %d\n", i, romanToInt(romanNumerals[i]));
    }

    return EXIT_SUCCESS;
}
