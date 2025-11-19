#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return strdup(s); // No zigzag needed

    int len = strlen(s);
    char* result = (char*)malloc(len + 1); // Allocate result string
    int pos = 0; // Position in result

    for (int row = 0; row < numRows; row++) {
        int i = row;
        int step1 = 2 * (numRows - row - 1);
        int step2 = 2 * row;

        while (i < len) {
            result[pos++] = s[i];

            // For the first or last row, only one step is needed
            if (step1 == 0 && step2 == 0) {
                i += 2 * (numRows - 1);
            } else if (step1 == 0) {
                i += step2;
            } else if (step2 == 0) {
                i += step1;
            } else {
                i += step1;
                if (i >= len) break;
                result[pos++] = s[i];
                i += step2;
            }
        }
    }

    result[pos] = '\0';
    return result;
}

// Example usage for testing locally
int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;
    char* converted = convert(s, numRows);
    printf("%s\n", converted); // Should print "PAHNAPLSIIGYIR"
    free(converted);
    return 0;
}

