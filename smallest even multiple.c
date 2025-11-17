#include <stdio.h>

int smallestEvenMultiple(int n) {
    return (n % 2 == 0) ? n : 2 * n;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int result = smallestEvenMultiple(n);
    printf("Smallest multiple of 2 and %d is: %d\n", n, result);

    return 0;
}
