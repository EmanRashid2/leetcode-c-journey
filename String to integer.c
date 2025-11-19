#include <limits.h>
#include <ctype.h>

int myAtoi(char *s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Skip leading whitespaces
    while (s[i] == ' ') i++;

    // 2. Handle optional sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3

