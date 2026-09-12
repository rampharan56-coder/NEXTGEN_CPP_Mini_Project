# Restaurant Order Line Management System

A C++ console application that simulates a restaurant order line using an Object-Oriented Programming (OOP) approach and a custom singly-linked list queue data structure with dynamic memory management.

---

## What the Program Does

The program manages customer orders in a FIFO (First-In, First-Out) queue. Each order stores an **Order ID**, **Customer Name**, **Food Name**, and **Price**.

### Key Features & Concepts
- **Add Order (`Enqueue`)**: Adds a new order to the rear of the queue using dynamically allocated memory (`new`).

- **Serve Order (`Dequeue`)**: Serves the order at the front of the queue, displays its details, and safely deallocates its memory (`delete`).

- **View Current Order (`Peek`)**: Inspects the order at the front of the queue in O(1) time without removing it, allowing staff to view the order currently being prepared.

- **Display All Orders**: Traverses the linked list from front to rear to show all pending orders and their positions in line.

- **Search Order**: Performs a linear search to find and display an order by its unique Order ID.

- **Sort Orders**: Uses a Selection Sort algorithm with at most O(N) pointer swaps to sort orders either by **Order ID** (ascending or descending) or by **Price** (lowest first or highest first).

- **Safe Memory Management**: Automatically deallocate all remaining nodes and orders upon program exit to prevent memory leaks.

---

## Project Structure

```text
.
├── include/
│   ├── Node.h          # Linked list node definition
│   ├── Order.h         # Order class declaration
│   └── OrderQueue.h    # Queue class declaration and prototypes
├── source/
│   ├── Node.cpp        # Node constructor definition
│   ├── Order.cpp       # Order class implementation
│   ├── OrderQueue.cpp  # Queue operations and sorting logic
│   └── main.cpp        # Interactive CLI menu and input helper
└── README.md
```

---

## How to Compile and Run

### Prerequisites
- A C++ compiler supporting C++17 or later (such as `g++` / MinGW on Windows or GCC/Clang on Linux/macOS).

### 1. Compile the Program

Open your terminal in the project root directory and run:

**Windows (PowerShell / Command Prompt):**
```powershell
g++ -std=c++17 -Iinclude source/*.cpp -o restaurant.exe
```

**Linux / macOS:**
```bash
g++ -std=c++17 -Iinclude source/*.cpp -o restaurant
```

> **Note**: The `-Iinclude` flag directs the compiler to search the `include/` directory for header files (`.h`).

---

### 2. Run the Program

**Windows:**
```powershell
./restaurant.exe
```

**Linux / macOS:**
```bash
./restaurant
```

---

## Example Usage

Upon running, you will be greeted with an interactive text menu:

```text
========================================
       RESTAURANT ORDER LINE
========================================
1. Add Order
2. Serve Order
3. View Current Order
4. Display All Orders
5. Search Order
6. Sort Orders
7. Exit
========================================
Enter your choice:
```
Enter the number corresponding to your desired action and follow the on-screen prompts.

