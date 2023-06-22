#include <stdio.h>

#define SIZE 5

int main() {
    int numbers[SIZE] = {10, 5, 30, -7, 20};
    int min = numbers[0];  // Initialize min with the first element
    int max = numbers[0];  // Initialize max with the first element

    // Find the minimum and maximum values
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    
    return 0;
}