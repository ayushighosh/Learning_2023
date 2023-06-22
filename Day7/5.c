#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person* person1, struct Person* person2);

int main() {
    struct Person person1, person2;

    printf("Enter details for person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);

    printf("\nEnter details for person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);

    printf("\nBefore swapping:\n");
    printf("Person 1 - Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2 - Name: %s, Age: %d\n", person2.name, person2.age);

    swapFields(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1 - Name: %s, Age: %d\n", person1.name, person1.age);
    printf("Person 2 - Name: %s, Age: %d\n", person2.name, person2.age);

    return 0;
}

void swapFields(struct Person* person1, struct Person* person2) {
    struct Person temp;

    temp = *person1;
    *person1 = *person2;
    *person2 = temp;
}

