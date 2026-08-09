#include <stdio.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

int main() {
    struct Account acc;
    int choice;
    float amount;

    acc.accountNumber = 0;
    acc.balance = 0;

    while (1) {
        printf("\n========== BANK MANAGEMENT SYSTEM ==========\n");
        printf("1. Create Account\n");
        printf("2. Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter Account Number: ");
                scanf("%d", &acc.accountNumber);

                printf("Enter Account Holder Name: ");
                scanf(" %[^\n]", acc.name);

                printf("Enter Initial Deposit: ");
                scanf("%f", &acc.balance);

                printf("\nAccount created successfully!\n");
                break;

            case 2:
                if (acc.accountNumber == 0) {
                    printf("\nPlease create an account first.\n");
                } else {
                    printf("\n----- Account Details -----\n");
                    printf("Account Number: %d\n", acc.accountNumber);
                    printf("Account Holder: %s\n", acc.name);
                    printf("Balance: %.2f\n", acc.balance);
                }
                break;

            case 3:
                if (acc.accountNumber == 0) {
                    printf("\nPlease create an account first.\n");
                } else {
                    printf("\nEnter amount to deposit: ");
                    scanf("%f", &amount);

                    if (amount > 0) {
                        acc.balance += amount;
                        printf("Money deposited successfully!\n");
                        printf("New Balance: %.2f\n", acc.balance);
                    } else {
                        printf("Invalid amount!\n");
                    }
                }
                break;

            case 4:
                if (acc.accountNumber == 0) {
                    printf("\nPlease create an account first.\n");
                } else {
                    printf("\nEnter amount to withdraw: ");
                    scanf("%f", &amount);

                    if (amount <= 0) {
                        printf("Invalid amount!\n");
                    } else if (amount > acc.balance) {
                        printf("Insufficient balance!\n");
                    } else {
                        acc.balance -= amount;
                        printf("Money withdrawn successfully!\n");
                        printf("Remaining Balance: %.2f\n", acc.balance);
                    }
                }
                break;

            case 5:
                if (acc.accountNumber == 0) {
                    printf("\nPlease create an account first.\n");
                } else {
                    printf("\nCurrent Balance: %.2f\n", acc.balance);
                }
                break;

            case 6:
                printf("\nThank you for using Bank Management System!\n");
                return 0;

        }
    }

    return 0;
}