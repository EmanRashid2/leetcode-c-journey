double myPow(double x, long long n) {
    if (n == 0) return 1.0;

    // If exponent is negative, invert x and use positive exponent
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }

    double result = 1.0;

    while (n > 0) {
        // If n is odd, multiply result by x
        if (n & 1)
            result *= x;

        // Square x
        x *= x;

        // Divide n by 2
        n >>= 1;
    }

    return result;
}

