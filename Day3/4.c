#include <stdio.h>

void findSmallestAndLargestDigits(int n) {
    int smallest = 9;
    int largest = 0;

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            temp /= 10;

            if (digit < smallest) {
                smallest = digit;
            }

            if (digit > largest) {
                largest = digit;
            }
        }
    }

    printf("Smallest digit: %d\n", smallest);
    printf("Largest digit: %d\n", largest);
}

int main() {
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    findSmallestAndLargestDigits(n);

    return 0;
}

