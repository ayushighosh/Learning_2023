#include <stdio.h>

int main() {
    double operand1, operand2, result;
    char operator;

    printf("Enter Number1: ");
    scanf("%lf", &operand1);

    printf("Enter the operator: ");
    scanf(" %c", &operator); // Notice the space before %c to consume any whitespace characters.

    printf("Enter Number2: ");
    scanf("%lf", &operand2);

    // Perform the calculation based on the operator
    switch (operator) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            // Check for division by zero
            if (operand2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1; // Exit the program with an error status
            }
            result = operand1 / operand2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1; // Exit the program with an error status
    }

    printf("Result: %.2lf\n", result);

    return 0; // Exit the program successfully
}

