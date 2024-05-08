# Hotel Management System Using C++

## Overview

This is a simple Hotel Management System implemented in C++. The system allows hotel staff to manage room bookings, customer check-ins and check-outs, and generate bills for customers.

## Features

- **User Authentication**: Users can log in with their username and password to access the system.
- **Check-In**: Allows hotel staff to register new customers, assign rooms, and record check-in details.
- **Check-Out**: Enables the check-out process for customers, calculating total bills based on the duration of stay and any additional charges.
- **Room Management**: Provides functionalities to add, modify, and delete rooms, as well as view room availability and details.
- **Customer Information**: Allows users to view information about specific customers or all customers currently checked-in.

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC, Clang)

### Installation

1. Clone the repository:
    ```
    git clone https://github.com/yourusername/hotel-management-system.git
    ```

2. Navigate to the project directory:
    ```
    cd hotel-management-system
    ```

3. Compile the code:
    ```
    g++ main.cpp -o hotel_management
    ```

### Usage

1. Run the compiled executable:
    ```
    ./hotel_management
    ```

2. Log in with your username and password.

3. Follow the on-screen instructions to perform various tasks such as check-in, check-out, room management, etc.

## File Structure

- `main.cpp`: Contains the main logic and functions for the Hotel Management System.
- `rooms.txt`: Stores information about hotel rooms.
- `customer_records.txt`: Stores records of checked-in customers.
- `temp_rooms.txt`: Temporary file used for room management operations.

## Contributing

Contributions are welcome! Feel free to fork the repository, make changes, and submit pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
