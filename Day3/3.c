#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;
    int temp = num;
    int divisor = 1;

    while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;

        int numberWithoutDigit = (num / (divisor * 10)) * divisor + (num % divisor);
        if (numberWithoutDigit > largest) {
            largest = numberWithoutDigit;
        }
        
        divisor *= 10;
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNumber = findLargestNumber(num);
    printf("Largest number after deleting a single digit: %d\n", largestNumber);

    return 0;
}


