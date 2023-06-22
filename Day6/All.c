#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int marks;
};

void parseString(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter name for student %d: ", i+1);
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  // Remove newline character

        printf("Enter marks for student %d: ", i+1);
        scanf("%d", &students[i].marks);
        getchar();  // Consume newline character
    }
}

void initialize(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        strcpy(students[i].name, "");
        students[i].marks = 0;
    }
}

void display(struct Student* students, int size) {
    printf("Students:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\nMarks: %d\n", students[i].name, students[i].marks);
    }
}

void sortByMarks(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j+1].marks) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int searchByName(struct Student* students, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();  // Consume newline character

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    parseString(students, size);

    printf("\n-- Initial Students --\n");
    display(students, size);

    sortByMarks(students, size);

    printf("\n-- Sorted Students --\n");
    display(students, size);

    char searchName[MAX_NAME_LENGTH];
    printf("\nEnter a name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline character

    int index = searchByName(students, size, searchName);
    if (index != -1) {
        printf("\n-- Found at index %d --\n", index);
        printf("Name: %s\nMarks: %d\n", students[index].name, students[index].marks);
    } else {
        printf("\n-- Not Found --\n");
    }

    free(students);
    return 0;
}

