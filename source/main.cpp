#include "../include/OrderQueue.h"
#include <iostream>
#include <string>

using namespace std;

// ============================================================
// Input Helper
// ============================================================

typedef struct
{
    string foodName;
    double price;
    int ID;
} Menu;

Order *createOrder()
{
    const Menu listFood[10] = {
        {.foodName = "Bai Sach Chrouk", .price = 2.5, .ID = 1},
        {.foodName = "Bai Mon", .price = 2.5, .ID = 2},
        {.foodName = "Lok Lak", .price = 3.50, .ID = 3},
        {.foodName = "Kuy Teav", .price = 2.00, .ID = 4},
        {.foodName = "Nom Banh Chok ", .price = 1.50, .ID = 5},
        {.foodName = "Fish Amok ", .price = 3.00, .ID = 6},
        {.foodName = "Chicken Amok", .price = 3.00, .ID = 7},
        {.foodName = "Iced Coffee", .price = 1.00, .ID = 8},
        {.foodName = "Coconut", .price = 1.50, .ID = 9},
        {.foodName = "Coca Cola", .price = 1.00, .ID = 10},
    };

    int tableID;
    string customer;
    int foodID[10] = {0};
    double price;

    cout << "\n========== Add New Order ==========" << endl;

    cout << "Your Table ID: ";
    while (!(cin >> tableID))
    {
        cout << "Invalid input. Order ID must be a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore();

    bool exit = false;
    int orderSize = 0;
    char input = ' ';

    while (!exit)
    {
        cout << "Food ID: ";
        cin >> foodID[orderSize];
        cout << "Anything else??, press [e] to exit : else press anything to continue order ";
        cin >> input;
        if (input == 'a')
        {
            exit = true;
        }
        else
        {
            orderSize++;
        }
    }

    // because we intialize this variable as an index of the array foodID, and its role is working as sizes of whole order as well
    // So after looping, this size it should be less than one if we compare to actual size in the foodID array
    orderSize++; 

    // Caculate total price
    double totalPrice = 0;
    string combineAsAtext;
    int toStopComma = 0;

    for (int i = 0; i < orderSize; i++) {

        bool found = false;

        for (int j = 0; j < orderSize && !found; j++) {
            if (foodID[i] == listFood[j].ID)
            {
                toStopComma++;
                totalPrice += listFood[i].price;
                combineAsAtext += listFood[i].foodName;
                if (toStopComma < orderSize) {
                    combineAsAtext += ", ";
                }
                found = true;
            }
        }
    }

    Order *newOrder = new Order(tableID, combineAsAtext, totalPrice);

    return newOrder;
}

// ============================================================
// Customer Menu
// (Customers can only place an order and view all orders)
// ============================================================

void customerMenu()
{
    cout << "--------------------------------\n";
    cout << "          |YOUR MENU|\n";
    cout << "--------------------------------\n";

    cout << "[1] Bai Sach Chrouk     $2.00\n";
    cout << "[2] Bai Mon             $2.50\n";
    cout << "[3] Lok Lak             $3.50\n";
    cout << "[4] Kuy Teav            $2.00\n";
    cout << "[5] Nom Banh Chok       $1.50\n";
    cout << "[6] Fish Amok           $3.00\n";
    cout << "[7] Chicken Amok        $3.00\n";
    cout << "[8] Iced Coffee         $1.00\n";
    cout << "[9] Coconut             $1.50\n";
    cout << "[10] Coca Cola          $1.00\n";

    cout << "--------------------------------\n";
}

void customerDisplay(OrderQueue &orderLine)
{
    int choice = 0;

    do
    {
        customerMenu();
        cout << "\n";
        cout << "========================================" << endl;
        cout << "             CUSTOMER MENU" << endl;
        cout << "========================================" << endl;
        cout << "[1] Place Order" << endl;
        cout << "[2] Display All Orders" << endl;
        cout << "[3] Back to Main Menu ->" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        if (!(cin >> choice))
        {
            cout << "\nInvalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Order *newOrder = createOrder();

            orderLine.enqueue(newOrder);

            break;
        }

        case 2:
        {
            orderLine.display();

            break;
        }

        case 3:
        {
            cout << "\nReturning to main menu..." << endl;

            break;
        }

        default:
        {
            cout << "\nInvalid choice. Please try again." << endl;
        }
        }

    } while (choice != 3);
}

// ============================================================
// Employee Menu
// (Employees have full access to all order queue functions)
// ============================================================
void employeeDisplay(OrderQueue &orderLine)
{
    int choice = 0;

    do
    {
        cout << "\n";
        cout << "========================================" << endl;
        cout << "             EMPLOYEE MENU" << endl;
        cout << "========================================" << endl;
        cout << "[1] Add Order" << endl;
        cout << "[2] Serve Order" << endl;
        cout << "[3] View Current Order" << endl;
        cout << "[4] Display All Orders" << endl;
        cout << "[5] Search Order" << endl;
        cout << "[6] Sort Orders" << endl;
        cout << "[7] Back to Main Menu ->" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        if (!(cin >> choice))
        {
            cout << "\nInvalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Order *newOrder = createOrder();

            orderLine.enqueue(newOrder);

            break;
        }

        case 2:
        {
            orderLine.dequeue();

            break;
        }

        case 3:
        {
            orderLine.peek();

            break;
        }

        case 4:
        {
            orderLine.display();

            break;
        }

        case 5:
        {
            int id;

            cout << "\nEnter Order ID to search: ";
            if (!(cin >> id))
            {
                cout << "Invalid input. Order ID must be a number." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            orderLine.search(id);

            break;
        }

        case 6:
        {
            int sortChoice;

            cout << "\n========== Sort Orders ==========" << endl;
            cout << "1. Sort by Order ID (Lowest First)" << endl;
            cout << "2. Sort by Order ID (Highest First)" << endl;
            cout << "3. Sort by Price (Lowest First)" << endl;
            cout << "4. Sort by Price (Highest First)" << endl;
            cout << "5. Cancel" << endl;
            cout << "=================================" << endl;
            cout << "Enter your choice: ";

            if (!(cin >> sortChoice))
            {
                cout << "\nInvalid choice. Please enter a number." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            switch (sortChoice)
            {
            case 1:
                orderLine.sortByID(true);
                orderLine.display();
                break;

            case 2:
                orderLine.sortByID(false);
                orderLine.display();
                break;

            case 3:
                orderLine.sortByPrice(true);
                orderLine.display();
                break;

            case 4:
                orderLine.sortByPrice(false);
                orderLine.display();
                break;

            case 5:
                cout << "\nSort cancelled." << endl;
                break;

            default:
                cout << "\nInvalid sort option. Returning to main menu." << endl;
                break;
            }

            break;
        }

        case 7:
        {
            cout << "\nReturning to main menu..." << endl;

            break;
        }

        default:
        {
            cout << "\nInvalid choice. Please try again." << endl;
        }
        }

    } while (choice != 7);
}

// ============================================================
// Main Function
// ============================================================
int main()
{
    OrderQueue orderLine;

    int choice;

    do
    {
        cout << "\n";
        cout << "========================================" << endl;
        cout << "       RESTAURANT ORDER LINE" << endl;
        cout << "========================================" << endl;
        cout << "[1] Employee" << endl;
        cout << "[2] Customer" << endl;
        cout << "[3] Exit" << endl;
        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        if (!(cin >> choice))
        {
            cout << "\nInvalid choice. Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            employeeDisplay(orderLine);

            break;
        }

        case 2:
        {
            customerDisplay(orderLine);

            break;
        }

        case 3:
        {
            cout << "\nExiting program..." << endl;

            break;
        }

        default:
        {
            cout << "\nInvalid choice. Please try again." << endl;
        }
        }

    } while (choice != 3);

    // When main ends, orderLine's destructor runs automatically.
    return 0;
}