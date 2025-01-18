
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *longest_common_prefix(char *strings[], int strSize) {
    
    if (strSize == 0) {
        return "";
    }

    // Prefix length.
    int plen = strlen(strings[0]); 
    // Allocate a writable buffer for the prefix.
    char *prefix = (char *)malloc(plen + 1);

    if (prefix == NULL) {
        return "";
    }

    strcpy(prefix, strings[0]);

    for (int i = 1; i < strSize; i++) {
        while (strncmp(prefix, strings[i], plen) != 0) {
            plen--;
            prefix[plen] = '\0';
            if (plen == 0) {
                free(prefix);
                return "";
            }
        }
    }

    return prefix;
}


int main() {
    // Test cases.
    char *strings[] = {"flower", "flow", "flight"};
    int strSize = sizeof(strings) / sizeof(strings[0]);

    char *prefix = longest_common_prefix(strings, strSize);
    
    if (prefix) {
        printf("Case #%d: %s\n", 0, prefix);
        free(prefix);
    }

    return EXIT_SUCCESS;
}
