
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

    int i = 0;

    while (i < len) {
    
        while (isspace(s[i])) {
            i++;
        }
        
        int start = i;

        while (isalnum(s[i])) {
            i++;
        }

        if (len == start + (i - start)) {
            // Length of last word.
            return i - start;
        }

        i++;
    }

    return 0;
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
