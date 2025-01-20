
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


int my_atou(char *s) {

    int result = 0;
    
    int i = 0;
    int sign = 1;

    while (isspace(s[i])) {
        i++;
    }

    if (s[i] == '-') {
        sign = -1;
        i++;
    }

    int len = strlen(&s[i]) - 1;

    while (isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        i++;
        len--;
    }

    return result * sign;
}


int main() {
    // Test cases.
    char *strNums[] = {
        "42", 
        " -042", 
        "1337c0d3", 
        "0-1", 
        "words and 987"
    };
    int expected_nums[] = {42, -42, 1337, 0, 0};
    int size = sizeof(strNums) / sizeof(strNums[0]);

    for (int i = 0; i < size; i++) {
        int result = my_atou(strNums[i]);
        assert(result == expected_nums[i]);
        printf("Case #%d: %d\n", i, result);
    }

    return EXIT_SUCCESS;
}
