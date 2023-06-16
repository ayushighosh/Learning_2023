#include <stdio.h>

void print_bits(int num) {
    for (int i = 31; i >= 0; i--) {   // Iterate from the most significant bit (bit 31) to the least significant bit (bit 0)
        int bit = (num >> i) & 1;     // Extract the i-th bit by shifting the number and performing bitwise AND with 1
        printf("%d", bit);
    }
    printf("\n");  // Print a new line after printing all the bits
}

int main() {
    int num;
    printf("Enter a 32-bit integer: ");
    scanf("%d", &num);
    printf("Binary representation:\n");
    print_bits(num);

    return 0;
}

