#include "../include/OrderQueue.h"
#include <iostream>
#include <string>

using namespace std;

// ============================================================
// Input Helper
// ============================================================
Order *createOrder()
{
    int id;
    string customer;
    string food;
    double price;

    cout << "\n========== Add New Order ==========" << endl;

    cout << "Order ID: ";
    while (!(cin >> id))
    {
        cout << "Invalid input. Order ID must be a number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cin.ignore();

    cout << "Customer Name: ";
    getline(cin, customer);

    cout << "Food Name: ";
    getline(cin, food);

    cout << "Price: $";
    while (!(cin >> price))
    {
        cout << "Invalid input. Price must be a number: $";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    Order *newOrder = new Order(id, customer, food, price);

    return newOrder;
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
        cout << "1. Add Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. View Current Order" << endl;
        cout << "4. Display All Orders" << endl;
        cout << "5. Search Order" << endl;
        cout << "6. Sort Orders" << endl;
        cout << "7. Exit" << endl;
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
            cout << "\nExiting program..." << endl;

            break;
        }

        default:
        {
            cout << "\nInvalid choice. Please try again." << endl;
        }
        }

    } while (choice != 7);

    // When main ends, orderLine's destructor runs automatically.
    return 0;
}
