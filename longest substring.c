#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s) {
    int index[256] = {0};  // stores last index + 1 of each character
    int maxLen = 0, start = 0;

    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char c = s[end];

        if (index[c] > start) {
            start = index[c];  // move start after previous occurrence
        }

        index[c] = end + 1;  // store current index + 1
        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
        }
    }

    return maxLen;
}

// Example usage
int main() {
    char s[] = "abcabcbb";
    printf("Longest substring length: %d\n", lengthOfLongestSubstring(s)); // Output: 3
    return 0;
}
