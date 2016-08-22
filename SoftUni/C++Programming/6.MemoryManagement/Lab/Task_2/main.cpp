/**
 * Make a shopping list application.
 */
#include <iostream>
#include <list>

#include "UserChoice.h"
#include "ControlData.h"

using namespace std;
void print_menu();

int main()
{
    UserChoice currentChoice = ADD;
    int choice;
    ControlData controlData;
    while (1)
    {
        print_menu();
        cout << "Make your choice: " << endl;
        cin >> choice;
        cin.get();
        cin.clear();
        fflush(stdin);
        switch (choice)
        {
            case(ADD):
            {
                cout << "Enter ID: ";
                unsigned int id;
                cin >> id;
                cout << "Enter name of item: ";
                string itemName;
                cin >> itemName;
                cin.get();
                cin.clear();
                fflush(stdin);
                ShopList shopList = ShopList(id, itemName);
                controlData.add_to_list(shopList);
                break;
            }
            case(REMOVE):
            {
                cout << "Enter ID to remove: ";
                unsigned int id;
                cin >> id;
                cin.get();
                cin.clear();
                fflush(stdin);
                controlData.remove_from_list_by_id(id);
                break;
            }
            case(PRINT):
            {
                controlData.print_list();
                break;
            }
            case(QUIT):
            {
                break;
            }
            default:
            {
                cout << "Wrong choise. Try again." << endl;
                break;
            }
        }
        if (choice == QUIT)
        {
            break;
        }
    }
    controlData.print_list();

    return 0;
}

void print_menu()
{
    cout << "0. Quit" << endl;
    cout << "1. Add" << endl;
    cout << "2. Remove by ID" << endl;
    cout << "3. Print" << endl;
}