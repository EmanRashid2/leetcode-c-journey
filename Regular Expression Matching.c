#include <stdbool.h>
#include <string.h>

#define MAX_LEN 1000  // adjust if needed

bool isMatch(char *s, char *p) {
    int m = strlen(s);
    int n = strlen(p);

    // Use fixed-size DP table to avoid malloc
    bool dp[MAX_LEN + 1][MAX_LEN + 1] = {false};

    dp[0][0] = true; // empty string matches empty pattern

    // Handle patterns like a*, a*b*, etc. matching empty string
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*' && j >= 2) {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                // '*' can match zero of the previous element
                dp[i][j] = dp[i][j - 2];

                // '*' can match one or more if previous element match*

