#include <stdio.h>

#define MAX_SEATS 10  // Define the maximum number of seats on the bus

// Function to display seat availability
void displaySeats(int seats[]) {
    printf("\nSeat Availability:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == 1)
            printf("Seat %d: Available\n", i + 1);
        else
            printf("Seat %d: Reserved\n", i + 1);
    }
}

// Function to book a seat
void bookSeat(int seats[]) {
    int seatNumber;
    printf("Enter seat number to book (1 to %d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
    } else if (seats[seatNumber - 1] == 0) {
        printf("Seat %d is already reserved.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = 0;  // Mark the seat as reserved
        printf("Seat %d has been successfully booked.\n", seatNumber);
        generateTicket(seatNumber);  // Generate a ticket for the reserved seat
    }
}

// Function to cancel a reservation
void cancelReservation(int seats[]) {
    int seatNumber;
    printf("Enter seat number to cancel (1 to %d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number!\n");
    } else if (seats[seatNumber - 1] == 1) {
        printf("Seat %d is not reserved.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = 1;  // Mark the seat as available
        printf("Reservation for Seat %d has been cancelled.\n", seatNumber);
    }
}

// Function to generate a ticket for a reserved seat
void generateTicket(int seatNumber) {
    printf("\n--- TICKET ---\n");
    printf("Seat Number: %d\n", seatNumber);
    printf("Reservation Status: Confirmed\n");
    printf("Thank you for booking with us!\n");
}

// Main menu to interact with the bus reservation system
int main() {
    int seats[MAX_SEATS] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  // All seats are available initially
    int choice;

    while (1) {
        printf("\n---- Bus Reservation System ----\n");
        printf("1. Display Seat Availability\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Reservation\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                cancelReservation(seats);
                break;
            case 4:
                printf("Thank you for using the Bus Reservation System! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
