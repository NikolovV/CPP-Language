#include <iostream>
#include <vector>
#include <string>

#include "Customer.h"
#include "Shop.h"
#include "MenuOption.h"

using namespace std;
// Predefine operators
inline float operator+=(float &totalSum, const Item &obj); // Only for Variant 2.
ostream& operator<<(ostream &output, const Customer &customer);
ostream& operator<<(ostream &output, const Shop &shop);
// User menu
void print_menu();

// Variant 2
void search_item(const vector<Item> &item, Customer &customer, const Shop &shop);
//

int main()
{
    
    // Test dump data. (Put some more if you like to.)
    vector<Item> data;
#if DEBUG
    Item it = Item("123", "chewing gum", 1.10);
    data.push_back(it);
    it = Item("456", "beer", 2.50);
    data.push_back(it);
    it = Item("789", "coffee", 1.10);
    data.push_back(it);
    it = Item("159", "chips", 2.20);
    data.push_back(it);
#endif
    Customer pe6o;

    Shop Bila = Shop();
    Bila.set_customer(&pe6o);
    Bila.set_items(&data);
    //

    print_menu();
    bool loop = true;
    while (loop)
    {
        cout << "Your choice: ";
        string userOption;
        cin >> userOption;
        cin.get();
        cin.clear();
        fflush(stdin);
        if (userOption.size() > 1)
        {
            cout << "Wrong choice. Use 'h' if you need help." << endl;
            continue;
        }
        // Accept and convert lower letter.
        if (islower(userOption[0]))
        {
            userOption[0] = toupper(userOption[0]);
        }
        switch (userOption[0])
        {
            case((int) ENTER_BARCOD):
            {
                // Variant 1.
                Bila.search_item();

                // Variant 2. Please give a recommendation which variant is good OOP.
//                search_item(data, pe6o, Bila); // Line::159
                break;
            }
            case((int) CHANGE_ITEM_PRICE):
            {
                Bila.change_item_price();
                break;
            }
            case((int) CUSTOMER_INFO):
            {
                Bila.print_shop_info();
                break;
            }
            case((int) ADD_ITEM):
            {
                Bila.add_item_to_base();
                break;
            }
            case((int) CLEAR_INVOICE):
            {
                // I mean current Person discard the invoice.
                pe6o.clear_invoice();
                break;
            }
            case((int) DISPLAY_TOTAL):
            {
                cout << "Total sum: " << pe6o.get_total() << " leva (customer invoice)" << endl;
                // Same as:
                cout << "Total sum: " << Bila.get_customer_total() << " leva (shop info)" << endl;
                break;
            }
            case((int) AMOUNT_MONEY):
            {
                // I think here customer pay his items. ???
                pe6o.set_change();
                break;
            }
            case((int) HELP):
            {
                print_menu();
                break;
            }
            case((int) EXIT):
            {
                loop = false;
                break;
            }
            default:
            {
                cout << "Use 'h' if you need help." << endl;
            }
        }
    }

    return 0;
}

float operator+=(float &totalSum, const Item &obj)
{
    cout << "+= operator" << endl;
    totalSum += obj._price;
    return totalSum;
}

ostream& operator<<(ostream &output, const Customer &customer)
{
    for (int i = 0; i < customer.shoppingCartItems.size(); ++i)
    {
        output << "Product barcode: " << customer.shoppingCartItems[i].get_barcode() << endl;
        output << "\tname: " << customer.shoppingCartItems[i].get_product_name() << endl;
        output << "\tprice: " << customer.shoppingCartItems[i].get_price() << endl;
    }
    return output;
}

void print_menu()
{
    cout << "CASHIER MENU" << endl;
    cout << "1. Enter 10-digit code." << endl;
    cout << "2. Change the price of an item." << endl;
    cout << "3. Display customer information about the purchase." << endl;
    cout << "4. Add item to the store." << endl;
    cout << "C. Clear invoice." << endl;
    cout << "T. Print Total." << endl;
    cout << "G. Amount of money." << endl;
    cout << "H. Help." << endl;
    cout << "0. Exit" << endl;
}
// Variant 2
//void search_item(const vector<Item> &item, Customer &customer, const Shop &shop)
//{
//    cout << "Enter 10-digit barcode: ";
//    string barcode;
//    getline(cin, barcode);
//    bool isFound = false;
//    for (int i = 0; i < item.size(); i++)
//    {
//        if (barcode.compare(item[i].get_barcode()) == 0)
//        {
//            Item temp = item[i];
//            customer.add_to_invoice(temp);
//            float total = customer.get_total();
//            total += item[i]; // use += operator
//            customer.set_total(total);
//            isFound = true;
//            //   cout << customer << endl;
//            break;
//        }
//        else if (!isFound && i == (item.size() - 1))
//        {
//            cout << "Item cannot be found!" << endl;
//        }
//    }
//}