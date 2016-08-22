#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>

#include "Customer.h"
#include "Item.h"

using namespace std;

class Shop {
public:

    Shop();
    Shop(string newName, string newBIC, string newAddress,
            Customer *customer, vector<Item> *items);
    virtual ~Shop();
    //    friend class Item;
    friend ostream& operator<<(ostream &output, const Shop &shop);
    friend float operator+=(float &totalSum, const Item &obj);

    void set_name(string newName);
    void set_BIC(string newBIC);
    void set_address(string newAddress);
    void set_customer(Customer *ordinaryCustomer);
    void set_items(vector<Item> *item);

    string get_name() const;
    string get_BIC() const;
    string get_address() const;
    float get_customer_total() const;

    void show_shop_info();
    // Variant 1.
    void search_item();
    //
    void add_item_to_base();
    void change_item_price();
    void print_shop_info();
private:
    bool is_empty_items();
    string _shopName;
    string _BIC;
    string _address;
    Customer *ordinaryCustomer;
    vector<Item> *shopItem;
};

#endif /* SHOP_H */

