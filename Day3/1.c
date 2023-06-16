#include <stdio.h>

void printIncreasing(int n);
void printSpaces(int n);
void printDecreasing(int n);

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print the pattern
    printIncreasing(n);
    printSpaces(n);
    printDecreasing(n);

    return 0;
}

void printIncreasing(int n) {
    int i;

    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    int i;

    printf("\n");

    for (i = 1; i <= n - 2; i++) {
        printf("%d", i);

        // Print spaces
        int j;
        for (j = 1; j <= 2 * (n - i) - 3; j++) {
            printf(" ");
        }

        printf("%d", i);
        printf("\n");
    }
}

void printDecreasing(int n) {
    int i;

    for (i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

