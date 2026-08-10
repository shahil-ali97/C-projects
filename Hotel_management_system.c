
#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    int room, days;
    float bill = 0;

    char name[50];

    printf("=====================================\n");
    printf("       HOTEL MANAGEMENT SYSTEM\n");
    printf("=====================================\n");

    printf("Enter Customer Name: ");
    fgets(name, sizeof(name), stdin);

    do {
        printf("\n----------- HOTEL MENU -----------\n");
        printf("1. Book Room\n");
        printf("2. Food Order\n");
        printf("3. Check Bill\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("----------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nAvailable Rooms:\n");
                printf("1. Single Room  - Rs. 1000/day\n");
                printf("2. Double Room  - Rs. 1800/day\n");
                printf("3. Deluxe Room  - Rs. 2500/day\n");

                printf("Enter room type: ");
                scanf("%d", &room);

                printf("Enter number of days: ");
                scanf("%d", &days);

                if(room == 1) {
                    bill = bill + (1000 * days);
                    printf("Single Room booked successfully!\n");
                }
                else if(room == 2) {
                    bill = bill + (1800 * days);
                    printf("Double Room booked successfully!\n");
                }
                else if(room == 3) {
                    bill = bill + (2500 * days);
                    printf("Deluxe Room booked successfully!\n");
                }
                else {
                    printf("Invalid room type!\n");
                }
                break;

            case 2:
                printf("\n----------- FOOD MENU -----------\n");
                printf("1. Breakfast - Rs. 150\n");
                printf("2. Lunch     - Rs. 250\n");
                printf("3. Dinner    - Rs. 300\n");
                printf("4. Tea       - Rs. 50\n");

                printf("Enter food choice: ");
                scanf("%d", &room);

                if(room == 1) {
                    bill = bill + 150;
                    printf("Breakfast ordered!\n");
                }
                else if(room == 2) {
                    bill = bill + 250;
                    printf("Lunch ordered!\n");
                }
                else if(room == 3) {
                    bill = bill + 300;
                    printf("Dinner ordered!\n");
                }
                else if(room == 4) {
                    bill = bill + 50;
                    printf("Tea ordered!\n");
                }
                else {
                    printf("Invalid food choice!\n");
                }
                break;

            case 3:
                printf("\n----------- BILL -----------\n");
                printf("Customer Name : %s", name);
                printf("Total Bill    : Rs. %.2f\n", bill);
                printf("----------------------------\n");
                break;

            case 4:
                printf("\n----------- CHECKOUT -----------\n");
                printf("Customer Name : %s", name);
                printf("Final Bill    : Rs. %.2f\n", bill);
                printf("Thank you for staying with us!\n");
                bill = 0;
                break;

            case 5:
                printf("\nThank you!.\n");
                break;

            
        }

    } while(choice != 5);

    return 0;
}

