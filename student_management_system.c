#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

// Add Student
void addStudent() {
    if (count >= MAX) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}

// Display Students
void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n========== Student Records ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll Number : %d", students[i].roll);
        printf("\nName        : %s", students[i].name);
        printf("\nMarks       : %.2f\n", students[i].marks);
    }
}

// Search Student
void searchStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].roll);
            printf("Name        : %s\n", students[i].name);
            printf("Marks       : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

// Update Student
void updateStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

// Delete Student
void deleteStudent() {
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {

            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

// Main Function
int main() {
    int choice;

    while (1) {

        printf("\n\n========== STUDENT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you for using Student Management System!\n");
                return 0;

           
        }
    }

    return 0;
}
