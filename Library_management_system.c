
#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int issued;
};

struct Book books[100];
int totalBooks = 0;
#pragma pack(push,_CRT_PACKING)
void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[totalBooks].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", books[totalBooks].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[totalBooks].author);

    books[totalBooks].issued = 0;
    totalBooks++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    int i;

    if (totalBooks == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n========== BOOK LIST ==========\n");

    for (i = 0; i < totalBooks; i++) {
        printf("\nBook ID     : %d", books[i].id);
        printf("\nBook Name   : %s", books[i].name);
        printf("\nAuthor      : %s", books[i].author);

        if (books[i].issued == 0)
            printf("\nStatus      : Available\n");
        else
            printf("\nStatus      : Issued\n");
    }
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++) {
        if (books[i].id == id) {

            if (books[i].issued == 1) {
                printf("\nBook is already issued.\n");
            } else {
                books[i].issued = 1;
                printf("\nBook issued successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++) {
        if (books[i].id == id) {

            if (books[i].issued == 0) {
                printf("\nBook is already available.\n");
            } else {
                books[i].issued = 0;
                printf("\nBook returned successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n================================");
        printf("\n   LIBRARY MANAGEMENT SYSTEM");
        printf("\n================================");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Issue Book");
        printf("\n4. Return Book");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                issueBook();
                break;

            case 4:
                returnBook();
                break;

            case 5:
                printf("\nThank you!\n");
                return 0;

            
        }
    }

    return 0;
}

