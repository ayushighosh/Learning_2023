#include <stdio.h>

#define SIZE 5

int main() {
    int numbers[SIZE] = {10, 20, 30, 40, 50};
    int sum = 0;

    // Calculate the sum of the array elements
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }

    float average = (float)sum / SIZE;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    
    return 0;
}