#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char phoneNumber[15];
} Contact;

Contact *createContact(char *firstName, char *lastName, char *phoneNumber) {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    if (newContact != NULL) {
        strncpy(newContact->firstName, firstName, 50);
        strncpy(newContact->lastName, lastName, 50);
        strncpy(newContact->phoneNumber, phoneNumber, 15);
    }
    return newContact;
}

Contact *searchContactByName(Contact **phoneBook, char *firstName, char *lastName) {
    for (int i = 0; i < 10; i++) {
        if (phoneBook[i] != NULL &&
            strcmp(phoneBook[i]->firstName, firstName) == 0 &&
            strcmp(phoneBook[i]->lastName, lastName) == 0) {
            return phoneBook[i];
        }
    }
    return NULL;
}

void displayContact(Contact *contact) {
    if (contact != NULL) {
        printf("%s %s %s\n", contact->firstName, contact->lastName, contact->phoneNumber);
    } else {
        printf("No contacts were found in the phonebook\n");
    }
}

void deleteContacts(Contact **phoneBook) {
    for (int i = 0; i < 10; i++) {
        if (phoneBook[i] != NULL) {
            free(phoneBook[i]);
            phoneBook[i] = NULL;
        }
    }
    printf("All contacts were deleted from the phonebook.\n");
}

int main() {
    Contact *phoneBook[10] = {NULL}; // Initialize all pointers to NULL

    while (1) {
        printf("Phonebook Menu:\n1. Add contacts.\n2. Display a contact by name.\n3. List all contacts.\n4. Delete all contacts.\n5. Exit the program.\nEnter your choice: ");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            for (int i = 0; i < 10; i++) {
                if (phoneBook[i] == NULL) {
                    char fn[50], ln[50], number[15];
                    printf("Contact #%d\nEnter First Name: ", i + 1);
                    scanf("%s", fn);
                    printf("Enter Last Name: ");
                    scanf("%s", ln);
                    printf("Enter Phone Number: ");
                    scanf("%s", number);

                    phoneBook[i] = createContact(fn, ln, number);
                    if (phoneBook[i] == NULL) {
                        printf("Memory allocation failed.\n");
                    }
                }
            }
        } else if (choice == 2) {
            char fn[50], ln[50];
            printf("Enter First Name: ");
            scanf("%s", fn);
            printf("Enter Last Name: ");
            scanf("%s", ln);

            Contact *contact = searchContactByName(phoneBook, fn, ln);
            displayContact(contact);
        } else if (choice == 3) {
            for (int i = 0; i < 10; i++) {
                if (phoneBook[i] != NULL) {
                    printf("Contact #%d: ", i + 1);
                    displayContact(phoneBook[i]);
                }
            }
        } else if (choice == 4) {
            deleteContacts(phoneBook);
        } else if (choice == 5) {
            deleteContacts(phoneBook); // Free memory before exiting
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Incorrect input\n");
        }
    }

    return 0;
}