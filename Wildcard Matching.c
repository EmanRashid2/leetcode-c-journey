#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isMatch(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);

    // dp[j] = match status for s[0..i] and p[0..j]
    bool* dp = (bool*)calloc(m + 1, sizeof(bool));
    bool* newdp = (bool*)calloc(m + 1, sizeof(bool));

    dp[0] = true;  // empty string matches empty pattern

    // Initialize pattern prefix with '*' to match empty string
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*')
            dp[j] = dp[j - 1];
        else
            dp[j] = false;
    }

    for (int i = 1; i <= n; i++) {
        newdp[0] = false;  // non-empty string can't match empty pattern

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                // '*' can match empty (newdp[j-1]) or match s[i-1] (dp[j])
                newdp[j] = newdp[j - 1] || dp[j];
            } else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                // single character match
                newdp[j] = dp[j - 1];
            } else {
                newdp[j] = false;
            }
        }

        // swap dp and newdp
        bool* temp = dp;
        dp = newdp;
        newdp = temp;
    }

    bool result = dp[m];

    free(dp);
    free(newdp);
    return result;
}

