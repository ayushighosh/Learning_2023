#include <stdio.h>

// Generic swap function
void swap(void* a, void* b, size_t size) {
    char* temp = (char*)malloc(size);

    // Copy contents of 'a' to temp
    memcpy(temp, a, size);

    // Copy contents of 'b' to 'a'
    memcpy(a, b, size);

    // Copy contents of temp to 'b'
    memcpy(b, temp, size);

    // Free the allocated memory
    free(temp);
}

int main() {
    int a = 5;
    int b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b, sizeof(int));

    printf("After swap: a = %d, b = %d\n", a, b);

    double c = 2.5;
    double d = 4.7;
    printf("Before swap: c = %f, d = %f\n", c, d);

    swap(&c, &d, sizeof(double));

    printf("After swap: c = %f, d = %f\n", c, d);

    return 0;
}

