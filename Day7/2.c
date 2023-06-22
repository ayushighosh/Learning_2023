#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

Complex readComplex();
void writeComplex(Complex c);
Complex addComplex(Complex c1, Complex c2);
Complex multiplyComplex(Complex c1, Complex c2);

int main() {
    Complex complex1, complex2, sum, product;

    // Reading complex numbers
    printf("Enter the first complex number:\n");
    complex1 = readComplex();

    printf("Enter the second complex number:\n");
    complex2 = readComplex();

    // Writing complex numbers
    printf("First complex number: ");
    writeComplex(complex1);

    printf("Second complex number: ");
    writeComplex(complex2);

    // Addition of complex numbers
    sum = addComplex(complex1, complex2);
    printf("Sum of the complex numbers: ");
    writeComplex(sum);

    // Multiplication of complex numbers
    product = multiplyComplex(complex1, complex2);
    printf("Product of the complex numbers: ");
    writeComplex(product);

    return 0;
}

Complex readComplex() {
    Complex c;

    printf("Enter the real part: ");
    scanf("%lf", &c.real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &c.imag);

    return c;
}

void writeComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2lf + %.2lfi\n", c.real, c.imag);
    else
        printf("%.2lf - %.2lfi\n", c.real, -c.imag);
}

Complex addComplex(Complex c1, Complex c2) {
    Complex sum;

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    return sum;
}

Complex multiplyComplex(Complex c1, Complex c2) {
    Complex product;

    product.real = c1.real * c2.real - c1.imag * c2.imag;
    product.imag = c1.real * c2.imag + c1.imag * c2.real;

    return product;
}

