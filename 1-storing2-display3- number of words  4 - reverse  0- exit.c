#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu
char menu() {
    printf("\n1-------------> Store a string\n");
    printf("2----------------> Display the string\n");
    printf("3----------------> Number of words\n");
    printf("4----------------> Reverse the string\n");
    printf("0----------------> Exit\n");
    printf("Enter your choice: ");
    char choice = getchar();
    getchar(); // Clear the newline character left by previous input
    return choice;
}

// Function to store a string
char *storing() {
    char array[80];
    char *type = NULL;
    printf("\nEnter a string: ");
    fgets(array, 80, stdin);
    array[strcspn(array, "\n")] = 0; // Remove newline character from input
    type = (char *)malloc(strlen(array) + 1);
    if (type != NULL) {
        strcpy(type, array);
    }
    return type;
}

// Function to display a string
void display(char *array) {
    if (array != NULL) {
        printf("\nStored string: %s\n", array);
    } else {
        printf("\nNo string stored yet!\n");
    }
}

// Function to reverse a string
void reverse(char *type) {
    if (type != NULL) {
        int length = strlen(type);
        int i, j; // Declare variables outside the loop
        for (i = 0, j = length - 1; i < j; i++, j--) {
            char temp = type[i];
            type[i] = type[j];
            type[j] = temp;
        }
        printf("\nReversed string: %s\n", type);
    } else {
        printf("\nNo string to reverse!\n");
    }
}

// Function to count words in a string
int words(char *array) {
    if (array == NULL) {
        return 0;
    }
    int count = 0;
    int in_word = 0;
    int i; // Declare variable outside the loop
    for (i = 0; array[i] != '\0'; i++) {
        if (array[i] == ' ' || array[i] == '\t' || array[i] == '\n') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

int main() {
    char choice;
    char *type = NULL;

    while ((choice = menu()) != '0') {
        switch (choice) {
            case '1':
                if (type != NULL) {
                    free(type); // Free previously allocated memory to avoid leaks
                }
                type = storing();
                break;
            case '2':
                display(type);
                break;
            case '3':
                printf("\nNumber of words: %d\n", words(type));
                break;
            case '4':
                reverse(type);
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
        printf("\nPress Enter to return to the menu.\n");
        getchar(); // Wait for the user to press Enter
    }

    if (type != NULL) {
        free(type); // Free allocated memory before exiting
    }
    printf("\nExiting program. Goodbye!\n");
    return 0;
}
