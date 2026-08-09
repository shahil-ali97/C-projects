
#include <stdio.h>

int main()
{
    int pin, choice;
    float balance = 10000;
    float amount;

    // ATM PIN
    printf("Enter ATM PIN: ");
    scanf("%d", &pin);
    
   
    if (pin != 1234)
    {
        printf("Wrong PIN!\n");
        return 0;
    }

    printf("\nLogin Successful!\n");

    while (1)
    {
        printf("\n===== ATM MANAGEMENT SYSTEM =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        
        switch (choice)
        {
            case 1:
                printf("\nYour Balance = Rs. %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: ");
                scanf("%f", &amount);

                if (amount > 0)
                {
                    balance = balance + amount;
                    printf("Money deposited successfully!\n");
                    printf("New Balance = Rs. %.2f\n", balance);
                }
                else
                {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &amount);

                if (amount <= 0)
                {
                    printf("Invalid amount!\n");
                }
                else if (amount > balance)
                {
                    printf("Insufficient Balance!\n");
                }
                else
                {
                    balance = balance - amount;
                    printf("Please collect your cash.\n");
                    printf("Remaining Balance = Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("\nThank you for using ATM!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}


