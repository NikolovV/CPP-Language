#include <iosfwd>

#include "Shop.h"

Shop::Shop() : _shopName("CandyShop"), _BIC("123456789"),
_address("Somewhere in the middle of nowhere"),
ordinaryCustomer(NULL), shopItem(NULL)
{
}

Shop::Shop(string newName, string newBIC, string newAddress,
           Customer *customer, vector<Item> *items)
: _shopName(newName), _BIC(newBIC), _address(newAddress),
ordinaryCustomer(customer), shopItem(items)
{
}

Shop::~Shop()
{
}
// setters

void Shop::set_name(string newName)
{
    this->_shopName = newName;
}

void Shop::set_BIC(string newBIC)
{
    this->_BIC = newBIC;
}

void Shop::set_address(string newAddress)
{
    this->_address = newAddress;
}

void Shop::set_customer(Customer *customer)
{
    this->ordinaryCustomer = customer;
}

void Shop::set_items(vector<Item> *item)
{
    this->shopItem = item;
}
//getters

string Shop::get_name() const
{
    return this->_shopName;
}

string Shop::get_BIC() const
{
    return this->_BIC;
}

string Shop::get_address() const
{
    return this->_address;
}

float Shop::get_customer_total() const
{
    return ordinaryCustomer->get_total();
}
// methods

bool Shop::is_empty_items()
{
    if (shopItem->empty())
    {
        return true;
    }
    return false;
}

void Shop::show_shop_info()
{
    cout << get_name() << "\t" << get_BIC() << endl;
    cout << get_address() << endl;
}

void Shop::add_item_to_base()
{
    Item temp;
    cout << "Enter product barcode: ";
    string newBarcode;
    cin >> newBarcode;
    cin.get();
    cin.clear();
    fflush(stdin);
    temp.set_barcode(newBarcode);

    cout << "Enter product name: ";
    string productName;
    getline(cin, productName);
    temp.set_product_name(productName);

    cout << "Enter product price: ";
    float price;
    cin >> price;
    temp.set_price(price);

    shopItem->push_back(temp);
}

void Shop::print_shop_info()
{
    cout << "\t\t\tINVOICE" << endl;
    cout << "=========================================================" << endl;
    cout << "Shop: " << get_name() << endl;
    cout << "BIC: " << get_BIC() << endl;
    cout << "Address: " << get_address() << endl;
    cout << "=========================================================" << endl;
    cout << *ordinaryCustomer;
    cout << "=========================================================" << endl;
    cout << "Total sum: " << ordinaryCustomer->get_total() << " leva" << endl;
    if (ordinaryCustomer->get_total() == 0)
    {
        cout << "Would you bay something?" << endl;
    }
    if (ordinaryCustomer->get_change() == 0.0)
    {
        cout << "Customer doesn't finish shopping! ";
        cout << "Please enter amount of money (option 'G')" << endl;
    }
    else
    {
        cout << "Change: " << ordinaryCustomer->get_change() << " leva" << endl;
    }
}

// Variant 1.

void Shop::change_item_price()
{
    if (is_empty_items())
    {
        cout << "No stock!" << endl;
        return;
    }
    cout << "Enter product barcode: ";
    string barcode;
    cin >> barcode;
    cin.get();
    cin.clear();
    fflush(stdin);
    bool isFound = false;
    for (int i = 0; i < shopItem->size(); i++)
    {
//        if (barcode.compare((*shopItem)[i].get_barcode()) == 0)
        if (barcode.compare(shopItem->at(i).get_barcode()) == 0)
        {
            cout << "Old price: " << shopItem->at(i).get_price() << endl;
            cout << "Enter new price: ";
            float newPrice;
            cin >> newPrice;
            cin.get();
            cin.clear();
            fflush(stdin);
//            (*shopItem)[i].set_price(newPrice);
            shopItem->at(i).set_price(newPrice);
            isFound = true;
            break;
        }
        else if (!isFound && i == (shopItem->size() - 1))
        {
            cout << "Item cannot be found!" << endl;
        }
    }
}

void Shop::search_item()
{
    if (is_empty_items())
    {
        cout << "No items, sorry. Come back when we get some stock." << endl;
        return;
    }
    cout << "Enter 10-digit barcode: ";
    string barcode;
    getline(cin, barcode);
    bool isFound = false;
    for (int i = 0; i < shopItem->size(); i++)
    {
//        if (barcode.compare((*shopItem)[i].get_barcode()) == 0)
        if (barcode.compare(shopItem->at(i).get_barcode()) == 0)
        {
            Item temp = shopItem->at(i);
            ordinaryCustomer->add_to_invoice(temp);
            float total = ordinaryCustomer->get_total();
//            total += (*shopItem)[i].get_price();
            total += shopItem->at(i).get_price();
            ordinaryCustomer->set_total(total);
            isFound = true;
            //   cout << customer << endl;
            break;
        }
        else if (!isFound && i == (shopItem->size() - 1))
        {
            cout << "Item cannot be found!" << endl;
        }
    }
}