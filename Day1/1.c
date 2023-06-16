#include <stdio.h>

int find_biggest_if_else(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1 = 10;
    int num2 = 5;

    int result_if_else = find_biggest_if_else(num1, num2);
    printf("Using if-else: %d\n", result_if_else);

    return 0;
}
