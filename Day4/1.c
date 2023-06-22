#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox;
    struct Box* ptrBox = &myBox;

    // Assign values to the box dimensions
    ptrBox->length = 2.5;
    ptrBox->width = 3.0;
    ptrBox->height = 4.0;

    // Calculate volume and surface area using (*) asterisk and (.) dot operators
    double volume = calculateVolume(&myBox);
    double surfaceArea = calculateSurfaceArea(&myBox);

    printf("Volume of the box: %.2f\n", volume);
    printf("Surface area of the box: %.2f\n", surfaceArea);

    return 0;
}

