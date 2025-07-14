#include <stdio.h>
#include <string.h>

#define MAX_SLOTS 10

// Structure to represent each parking slot
typedef struct {
    int isOccupied;
    char vehicleNumber[20];
    char type[10];
} ParkingSlot;

// Function declarations
void parkVehicle(ParkingSlot slots[]);
void removeVehicle(ParkingSlot slots[]);
void displayStatus(ParkingSlot slots[]);
void countVehicles(ParkingSlot slots[]);

int main() {
    ParkingSlot slots[MAX_SLOTS] = {0}; // initialize all slots as empty
    int choice;

    while(1) {
        printf("\n--- Parking Lot Menu ---\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Status\n");
        printf("4. Total Vehicles\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                parkVehicle(slots);
                break;
            case 2:
                removeVehicle(slots);
                break;
            case 3:
                displayStatus(slots);
                break;
            case 4:
                countVehicles(slots);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to park a vehicle
void parkVehicle(ParkingSlot slots[]) {
    char vehicleNo[20], type[10];
    printf("Enter Vehicle Number: ");
    fgets(vehicleNo, sizeof(vehicleNo), stdin);
    vehicleNo[strcspn(vehicleNo, "\n")] = '\0'; // remove newline

    printf("Enter Vehicle Type (Car/Bike): ");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = '\0';

    // Prevent duplicate vehicle numbers
    for(int i = 0; i < MAX_SLOTS; i++) {
        if(slots[i].isOccupied && strcmp(slots[i].vehicleNumber, vehicleNo) == 0) {
            printf("Vehicle number already parked!\n");
            return;
        }
    }

    for(int i = 0; i < MAX_SLOTS; i++) {
        if(!slots[i].isOccupied) {
            slots[i].isOccupied = 1;
            strcpy(slots[i].vehicleNumber, vehicleNo);
            strcpy(slots[i].type, type);
            printf("Vehicle parked at slot %d.\n", i + 1);
            return;
        }
    }
    printf("Parking lot is full!\n");
}

// Function to remove a vehicle
void removeVehicle(ParkingSlot slots[]) {
    char vehicleNo[20];
    printf("Enter Vehicle Number to remove: ");
    fgets(vehicleNo, sizeof(vehicleNo), stdin);
    vehicleNo[strcspn(vehicleNo, "\n")] = '\0';

    for(int i = 0; i < MAX_SLOTS; i++) {
        if(slots[i].isOccupied && strcmp(slots[i].vehicleNumber, vehicleNo) == 0) {
            slots[i].isOccupied = 0;
            printf("Vehicle %s removed from Slot No: %d\n", vehicleNo, i + 1);
            return;
        }
    }
    printf("Vehicle not found!\n");
}

// Function to display current parking status
void displayStatus(ParkingSlot slots[]) {
    printf("\n--- Parking Lot Status ---\n");
    printf("Slot No   Vehicle No      Type\n");
    for(int i = 0; i < MAX_SLOTS; i++) {
        if(slots[i].isOccupied) {
            printf("%-9d %-15s %s\n", i + 1, slots[i].vehicleNumber, slots[i].type);
        } else {
            printf("%-9d EMPTY\n", i + 1);
        }
    }
}

// Function to count number of vehicles
void countVehicles(ParkingSlot slots[]) {
    int count = 0;
    for(int i = 0; i < MAX_SLOTS; i++) {
        if(slots[i].isOccupied)
            count++;
    }
    printf("Total vehicles parked: %d\n", count);
}

