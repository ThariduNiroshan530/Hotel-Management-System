#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>
#include <string>

// Define structures
struct Customer {
    int roomNumber;
    char name[30];
    char address[30];
    long phone;
    int familyMembers;
    char checkInDate[15];
    int numOfDays;
    float roomCost;
    int Numberofdaysstaying;
};

struct Bill {
    int roomNumber;
    char name[30];
    char address[30];
    long phone;
    int familyMembers;
    char checkInDate[15];
    int numOfDays;
    float roomCost;
	float otherCharges;
    float otherCost;
    float totalCost;
	std::string checkOutDate; // Add checkOutDate member here
};

struct Room {
    int roomNumber;
    int extraBedPrice;
    int extraPillowPrice;
    int extraBlanketPrice;
    int extraTowelPrice;
    char bedType[15];
    char roomType[30];
    float roomCost;
    bool available;
};

// Function prototypes
void login();
void checkIn();
void checkOut();
void displayCustomerInfo();
void displayBillInfo();
void manageRooms();
void addRoom();
void modifyRoom(); 
void deleteRoom(int roomNumber); // Add room number parameter
void displayRoomInfo();
void modifyRoomAvailability(int roomNumber, bool availability);
void deleteCustomerRecord(int roomNumber);
bool validateInput(int input, int min, int max);
void displayGuidelines();

bool isLoggedIn = false;

int main() {
    login();

    if (isLoggedIn) {
        char choice;
        do {
            std::cout << "*************\n";
            std::cout << "* MAIN MENU *\n";
            std::cout << "*************\n";
            std::cout << "1. Check-In\n";
            std::cout << "2. Check-Out\n";
            std::cout << "3. Customer Info\n";
            std::cout << "4. Manage-Rooms\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case '1':
                    checkIn();
                    break;
                case '2':
                    checkOut();
                    break;
                case '3':
                    displayCustomerInfo();
                    break;
                case '4':
                    manageRooms();
                    break;
                case '5':
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice! Please try again.\n";
            }
        } while (choice != '5');
    } else {
        std::cout << "Login failed. Exiting...\n";
    }

    return 0;
}

void login() {
    std::string username, password;
    std::cout << "******************************************************************************\n";
    std::cout << "***                              LOGIN MENU                                ***\n";
    std::cout << "******************************************************************************\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    // Simple hardcoded login credentials
    if (username == "admin" && password == "password") {
        std::cout << "Login successful!\n";
        isLoggedIn = true;
    } else {
        std::cout << "Invalid username or password.\n";
    }
}

void checkIn() {
    Customer customer;
    Room room;

    // Get customer details
    std::cout << "Enter customer details:\n";
    std::cout << "Name: ";
    std::cin >> std::ws;
    std::cin.getline(customer.name, 30);
    std::cout << "Address: ";
    std::cin.getline(customer.address, 30);
    std::cout << "Phone number: ";
    std::cin >> customer.phone;
    std::cout << "Number of family members:";
    std::cin >> customer.familyMembers;
    std::cout << "Check-in date: ";
    std::cin >> customer.checkInDate;
    std::cout << "Number of days staying: ";
    std::cin >> customer.numOfDays;
    std::cout << "Room number: ";
    std::cin >> customer.roomNumber;

 // Define MAX_ROOMS
const int MAX_ROOMS = 100; // Example value, adjust as needed

 // Validate room number
    if (!validateInput(customer.roomNumber, 1, MAX_ROOMS)) {
        std::cout << "Invalid room number.\n";
        return;
    }

    std::cout << "Check-in successful!\n";
}



void generateInvoice(const Customer& customer) {
    // Fixed room cost per day
    const float ROOM_COST_PER_DAY = 5000;

    // Calculate total amount due
    float totalDue = ROOM_COST_PER_DAY * customer.Numberofdaysstaying;

    // Display invoice
    std::cout << "\nInvoice Details:\n";
    std::cout << "----------------\n";
    std::cout << "Customer Name: " << customer.name << "\n";
    std::cout << "Room Cost per Day: Rs." << ROOM_COST_PER_DAY << "\n";
    std::cout << "Number of Days Stayed: " << customer.Numberofdaysstaying << "\n";
    std::cout << "Total Amount Due: Rs." << totalDue << "\n";
}

void checkOut() {
    int roomNumber;
    Customer customer;

    // Get room number for check-out
    std::cout << "Enter room number for check-out: ";
    std::cin >> roomNumber;

    // Define MAX_ROOMS
    const int MAX_ROOMS = 100; // Example value, adjust as needed

    // Validate room number
    if (!validateInput(roomNumber, 1, MAX_ROOMS)) {
        std::cout << "Invalid room number.\n";
        return;
    }


     // Fixed room cost per day
    const float ROOM_COST_PER_DAY = 5000;

    // Calculate total amount due
    float totalDue = ROOM_COST_PER_DAY * customer.Numberofdaysstaying;


    // Display customer details
    std::cout << "\nEnter customer details:\n";
    std::cout << "Name: ";
    std::cin >> std::ws;
    std::cin.getline(customer.name, 30);
    std::cout << "Address: ";
    std::cin.getline(customer.address, 30);
    std::cout << "Phone number: ";
    std::cin >> customer.phone;
    std::cout << "Number of family members: ";
    std::cin >> customer.familyMembers;
    std::cout << "Check-in date: ";
    std::cin >> customer.checkInDate;
    std::cout << "Number of days staying: ";
    std::cin >> customer.Numberofdaysstaying; // Corrected variable name
    std::cout << "Total bill: " << ROOM_COST_PER_DAY * customer.Numberofdaysstaying << "\n";

    std::cout << "\nCheck-out successful!\n";

    // Generate invoice
    generateInvoice(customer);
}




void displayCustomerInfo() {
    char choice;
    int roomNumber;
    Customer customer;

    // Ask the user whether they want to display information for a specific customer or all customers
    std::cout << "Do you want to display information for a specific customer? (Y/N): ";
    std::cin >> choice;

    if (toupper(choice) == 'Y') {
        // Ask for the room number of the specific customer
        std::cout << "Enter room number: ";
        std::cin >> roomNumber;

 // Define MAX_ROOMS
const int MAX_ROOMS = 100; // Example value, adjust as needed

        // Validate room number
        if (!validateInput(roomNumber, 1, MAX_ROOMS)) {
            std::cout << "Invalid room number.\n";
            return;
        }

        // Display customer details
        std::cout << "\nCustomer details:\n";
        std::cout << "Name: " << customer.name << "\n";
        std::cout << "Address: " << customer.address << "\n";
        std::cout << "Phone number: " << customer.phone << "\n";
        std::cout << "Number of family members: " << customer.familyMembers << "\n";
        std::cout << "Check-in date: " << customer.checkInDate << "\n";
        std::cout << "Number of days staying: " << customer.numOfDays << "\n";
    } else if (toupper(choice) == 'N') {
        // Display information for all customers currently checked in
        // Iterate through all customer records
        std::cout << "\nCustomer information for all rooms:\n";
        // Implement logic to iterate through all customer records and display details
        // You need to retrieve customer details for each room and display them
    } else {
        std::cout << "Invalid choice.\n";
        return;
    }
}


void displayBillInfo() {
    char choice;
    int roomNumber;
    Bill bill;

    // Ask the user whether they want to display information for a specific bill or all bills
    std::cout << "Do you want to display information for a specific bill? (Y/N): ";
    std::cin >> choice;

    if (toupper(choice) == 'Y') {
        // Ask for the room number of the specific customer
        std::cout << "Enter room number: ";
        std::cin >> roomNumber;

 // Define MAX_ROOMS
const int MAX_ROOMS = 100; // Example value, adjust as needed

        // Validate room number
        if (!validateInput(roomNumber, 1, MAX_ROOMS)) {
            std::cout << "Invalid room number.\n";
            return;
        }

        // Display bill details
        std::cout << "\nBill details for room " << roomNumber << ":\n";
        std::cout << "Room number: " << bill.roomNumber << "\n";
        std::cout << "Total cost: " << bill.totalCost << "\n";
        std::cout << "Other charges: " << bill.otherCharges << "\n";
        std::cout << "Check-out date: " << bill.checkOutDate << "\n";
    } else if (toupper(choice) == 'N') {
        // Display information for all checked-out customers
        // Iterate through all bill records
        std::cout << "\nBill information for all checked-out customers:\n";
        // Implement logic to iterate through all bill records and display details
        // You need to retrieve bill details for each checked-out customer and display them
    } else {
        std::cout << "Invalid choice.\n";
        return;
    }
}



void manageRooms() {
    char choice;

    while (true) {
        // Display menu options
        std::cout << "\nROOM MANAGEMENT MENU\n";
        std::cout << "1. Add Room\n";
        std::cout << "2. Modify Room\n";
        std::cout << "3. Delete Room\n";
        std::cout << "4. Display Room Info\n";
        std::cout << "5. Return\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addRoom();
                break;
            case '2':
                modifyRoom();
                break;
           case '3':
                int roomNumberToDelete;
                std::cout << "Enter the room number to delete: ";
                std::cin >> roomNumberToDelete;
                deleteRoom(roomNumberToDelete); // Call deleteRoom with the room number
                break;
            case '4':
                displayRoomInfo();
                break;
            case '5':
                return; // Return to previous menu
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void addRoom() {
    Room newRoom;

    // Prompt user for room details
    std::cout << "Enter Room Number: ";
    std::cin >> newRoom.roomNumber;

    std::cout << "Enter Room Type: ";
    std::cin >> newRoom.roomType;

    std::cout << "Enter Bed Type: ";
    std::cin >> newRoom.bedType;

    std::cout << "Enter Room Cost: ";
    std::cin >> newRoom.roomCost;

    // Open file to append new room data
    std::ofstream outFile("rooms.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    // Write new room data to file
    outFile << newRoom.roomNumber << " " << newRoom.roomType << " " << newRoom.bedType << " " << newRoom.roomCost << std::endl;

    // Close the file
    outFile.close();

    std::cout << "Room added successfully!\n";
}


void modifyRoom() {
    int targetRoomNumber;
    std::cout << "Enter Room Number to Modify: ";
    std::cin >> targetRoomNumber;

    // Open file to read existing room data
    std::ifstream inFile("rooms.txdeleteCustomerRecordt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    std::stringstream tempFile;
    bool roomFound = false;
    Room currentRoom;

    // Read each line from the file
    while (inFile >> currentRoom.roomNumber >> currentRoom.roomType >> currentRoom.bedType >> currentRoom.roomCost) {
        // Check if the current room matches the target room number
        if (currentRoom.roomNumber == targetRoomNumber) {
            roomFound = true;

            // Display current room details
            std::cout << "Current Room Details:\n";
            std::cout << "Room Number: " << currentRoom.roomNumber << std::endl;
            std::cout << "Room Type: " << currentRoom.roomType << std::endl;
            std::cout << "Bed Type: " << currentRoom.bedType << std::endl;
            std::cout << "Room Cost: " << currentRoom.roomCost << std::endl;

            // Prompt user to enter new details
            std::cout << "\nEnter New Details:\n";
            std::cout << "Room Type: ";
            std::cin >> currentRoom.roomType;
            std::cout << "Bed Type: ";
            std::cin >> currentRoom.bedType;
            std::cout << "Room Cost: ";
            std::cin >> currentRoom.roomCost;
        }
        // Write room details to temporary file
        tempFile << currentRoom.roomNumber << " " << currentRoom.roomType << " " << currentRoom.bedType << " " << currentRoom.roomCost << std::endl;
    }

    // Close the file
    inFile.close();

    // Rewrite the contents of the original file with modifications
    std::ofstream outFile("rooms.txt");
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    outFile << tempFile.str();
    outFile.close();

    if (roomFound) {
        std::cout << "Room details modified successfully!\n";
    } else {
        std::cout << "Room not found!\n";
    }
}


void deleteRoom(int roomNumber) {
    std::ifstream inFile("rooms.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    std::ofstream tempFile("temp_rooms.txt");
    if (!tempFile) {
        std::cerr << "Error: Unable to open temporary file for writing.\n";
        inFile.close();
        return;
    }

    bool roomFound = false;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int currentRoomNumber;
        if (!(iss >> currentRoomNumber)) {
            std::cerr << "Error: Invalid data format in file.\n";
            inFile.close();
            tempFile.close();
            return;
        }

        if (currentRoomNumber == roomNumber) {
            roomFound = true;
        } else {
            tempFile << line << std::endl;
        }
    }

    inFile.close();
    tempFile.close();

    if (roomFound) {
        if (remove("rooms.txt") != 0) {
            std::cerr << "Error: Unable to delete original file.\n";
            return;
        }
        if (rename("temp_rooms.txt", "rooms.txt") != 0) {
            std::cerr << "Error: Unable to rename temporary file.\n";
            return;
        }
        std::cout << "Room " << roomNumber << " has been deleted successfully.\n";
    } else {
        std::cout << "Room not found.\n";
        remove("temp_rooms.txt"); // Remove temporary file if room not found
    }
}



void displayRoomInfo() {
    std::ifstream inFile("rooms.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    std::string line;
    std::cout << "Room Information:\n";
    std::cout << "-----------------\n";
    std::cout << "Room No.\tType\t\tBed Type\tCost\n";
    std::cout << "-------------------------------------------------\n";

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int roomNumber;
        std::string roomType, bedType;
        float roomCost;

        if (!(iss >> roomNumber >> roomType >> bedType >> roomCost)) {
            std::cerr << "Error: Invalid data format in file.\n";
            inFile.close();
            return;
        }

        std::cout << roomNumber << "\t\t" << roomType << "\t\t" << bedType << "\t\t$" << roomCost << std::endl;
    }

    inFile.close();
}



void modifyRoomAvailability(int roomNumber, bool availability) {
    // Open the file for both reading and writing
    std::fstream file("rooms.txt", std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Error: Unable to open file for reading and writing.\n";
        return;
    }

    // Search for the room with the given room number
    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        int currentRoomNumber;
        bool currentAvailability;
        if (std::sscanf(line.c_str(), "%d %d", &currentRoomNumber, &currentAvailability) == 2) {
            if (currentRoomNumber == roomNumber) {
                // Update the availability status of the room
                file.seekp(file.tellg() - static_cast<std::streampos>(line.length()) - 1); // Move the write pointer back to the beginning of the line
                file << roomNumber << " " << availability; // Update the line with the new availability
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cerr << "Error: Room with number " << roomNumber << " not found.\n";
    } else {
        std::cout << "Room availability updated successfully.\n";
    }

    // Close the file
    file.close();
}


void deleteCustomerRecord(int roomNumber) {
    // Open the file for both reading and writing
    std::ifstream inFile("customer_records.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    std::ofstream outFile("temp.txt");
    if (!outFile) {
        std::cerr << "Error: Unable to open temporary file for writing.\n";
        return;
    }

    // Search for the customer record with the given room number
    std::string line;
    bool found = false;
    while (std::getline(inFile, line)) {
        int currentRoomNumber;
        if (std::sscanf(line.c_str(), "%d", &currentRoomNumber) == 1) {
            if (currentRoomNumber != roomNumber) {
                // If the room number doesn't match, write the record to the temporary file
                outFile << line << std::endl;
            } else {
                found = true;
            }
        }
    }

    inFile.close();
    outFile.close();

    // Delete the original file and rename the temporary file
    if (found) {
        std::remove("customer_records.txt");
        std::rename("temp.txt", "customer_records.txt");
        std::cout << "Customer record for room " << roomNumber << " deleted successfully.\n";
    } else {
        std::cerr << "Error: Customer record for room " << roomNumber << " not found.\n";
        std::remove("temp.txt");
    }
}



bool validateInput(int input, int min, int max) {
    return (input >= min && input <= max);
}

void displayGuidelines() {
    std::cout << "Welcome to the Hotel Management System!\n";
    std::cout << "Guidelines:\n";
    std::cout << "1. Please follow the on-screen instructions carefully.\n";
    std::cout << "2. Enter numeric choices when prompted.\n";
    std::cout << "3. Use appropriate inputs for each field.\n";
    std::cout << "4. Ensure data accuracy to avoid errors in the system.\n";
    std::cout << "5. Contact support for any assistance or issues.\n";
}