#include <stdio.h>

int stringToInteger(const char* str) {
    int res = 0;
    int i = 0;
    int sign = 1;
    
    // Check for negative sign
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }
    
    // Iterate through each character of the string
    for (; str[i] != '\0'; i++) {
        int digit = str[i] - '0';
        
        // Check if the character is a valid digit
        if (digit >= 0 && digit <= 9) {
            // Update the result by multiplying it by 10 and adding the current digit
            res = res * 10 + digit;
        } else {
            // Invalid character found
            // You can handle the error or break the loop here
            break;
        }
    }
    
    return res * sign;
}

int main() {
    const char str[] = "5278";
    
    int value = stringToInteger(str);
    
    printf("String: %s\n", str);
    printf("Integer value: %d\n", value);
    
    return 0;
}
