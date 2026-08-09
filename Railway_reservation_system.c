#include <stdio.h>
#include <string.h>

struct Passenger {
    int ticketNo;
    char name[50];
    int age;
    char train[50];
    char source[30];
    char destination[30];
    int seatNo;
    int booked;
};

int main() {
    struct Passenger p[100];
    int choice, i;
    int ticketCounter = 1000;
    int seatNumber;
    int found;

    // Initially all seats are available
    for (i = 0; i < 100; i++) {
        p[i].booked = 0;
    }

    while (1) {

        printf("\n====================================\n");
        printf("     RAILWAY RESERVATION SYSTEM\n");
        printf("====================================\n");
        printf("1. Book Ticket\n");
        printf("2. View Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Check Available Seats\n");
        printf("5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                found = 0;

                // Find an empty seat
                for (i = 0; i < 100; i++) {
                    if (p[i].booked == 0) {
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nSorry! No seats available.\n");
                    break;
                }

                p[i].ticketNo = ++ticketCounter;
                p[i].seatNo = i + 1;

                printf("\nEnter Passenger Name: ");
                scanf(" %[^\n]", p[i].name);

                printf("Enter Age: ");
                scanf("%d", &p[i].age);

                printf("Enter Train Name: ");
                scanf(" %[^\n]", p[i].train);

                printf("Enter Source: ");
                scanf(" %[^\n]", p[i].source);

                printf("Enter Destination: ");
                scanf(" %[^\n]", p[i].destination);

                p[i].booked = 1;

                printf("\nTicket booked successfully!\n");
                printf("Ticket Number: %d\n", p[i].ticketNo);
                printf("Seat Number: %d\n", p[i].seatNo);

                break;

            case 2:
                printf("\nEnter Ticket Number: ");
                scanf("%d", &ticketCounter);

                found = 0;

                for (i = 0; i < 100; i++) {
                    if (p[i].booked == 1 &&
                        p[i].ticketNo == ticketCounter) {

                        printf("\n========== TICKET DETAILS ==========\n");
                        printf("Ticket Number : %d\n", p[i].ticketNo);
                        printf("Passenger Name: %s\n", p[i].name);
                        printf("Age           : %d\n", p[i].age);
                        printf("Train         : %s\n", p[i].train);
                        printf("From          : %s\n", p[i].source);
                        printf("To            : %s\n", p[i].destination);
                        printf("Seat Number   : %d\n", p[i].seatNo);
                        printf("====================================\n");

                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nTicket not found!\n");
                }

                break;

            case 3:
                printf("\nEnter Ticket Number to cancel: ");
                scanf("%d", &seatNumber);

                found = 0;

                for (i = 0; i < 100; i++) {
                    if (p[i].booked == 1 &&
                        p[i].ticketNo == seatNumber) {

                        p[i].booked = 0;

                        printf("\nTicket cancelled successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("\nTicket not found!\n");
                }

                break;

            case 4:
                found = 0;

                for (i = 0; i < 100; i++) {
                    if (p[i].booked == 0) {
                        found++;
                    }
                }

                printf("\nTotal Seats     : 100\n");
                printf("Available Seats : %d\n", found);
                printf("Booked Seats    : %d\n", 100 - found);

                break;

            case 5:
                printf("\nThank you for using Railway Reservation System!\n");
                return 0;

            
        }
    }

    return 0;
}