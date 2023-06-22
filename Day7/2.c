#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void changeCase(char *buffer, int bufferSize, int option) {
    int i;

    switch (option) {
        case 'u': // Convert to uppercase
            for (i = 0; i < bufferSize; i++) {
                buffer[i] = toupper(buffer[i]);
            }
            break;
        case 'l': // Convert to lowercase
            for (i = 0; i < bufferSize; i++) {
                buffer[i] = tolower(buffer[i]);
            }
            break;
        case 's': // Convert to sentence case
            buffer[0] = toupper(buffer[0]);
            for (i = 1; i < bufferSize; i++) {
                if (buffer[i - 1] == '.' || buffer[i - 1] == '?' || buffer[i - 1] == '!') {
                    buffer[i] = toupper(buffer[i]);
                } else {
                    buffer[i] = tolower(buffer[i]);
                }
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int option = 0;

    // Get the source file path from the user
    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Get the target file path from the user
    printf("Enter the path of the target file: ");
    scanf("%s", targetPath);

    // Open the target file in write mode
    targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Check if an option was provided
    if (argc > 1) {
        option = argv[1][1];
    }

    // Copy the contents of the source file to the target file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (option != 0) {
            changeCase(buffer, bytesRead, option);
        }
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}

