
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


int length_of_last_word(char *s) {
    
    int len = strlen(s);

    while (len > 0 && isspace(s[len - 1])) {
        len--;
    }
    
    if (len == 0) {
        return 0;
    }

    int i = len - 1;

    while (i >= 0 && isalnum(s[i])) {
        i--;
    }

    return len - 1 - i;
}


int main() {
    // Test cases.
    char *words[] = {
        "Hello World", // World: 5
        "   fly me   to   the moon  ", // Moon: 4 
        "luffy is still joyboy" // joyboy: 6
    };
    int expected_lengths[] = {5, 4, 6};
    int size = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < size; i++) {
        int length = length_of_last_word(words[i]);
        assert(expected_lengths[i] == length);
        printf("Case #%d: %d\n", i, length);
    }

    return EXIT_SUCCESS;
}
