#include <stdio.h>

void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52;
    
    //Print hexadecimal
    printf("Hexadecimal: 0x%llX\n", exponent);
    
    // Print binary representation
    printf("Binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);
    return 0;
}
