#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>

#include "Item.h"
using namespace std;

class Customer {
public:
    Customer();
    virtual ~Customer();
    friend ostream& operator<<(ostream &output, const Customer &customer);

    void add_to_invoice(const Item &item);
    void clear_invoice();

    void set_total(float total);
    void set_change();

    float get_total() const;
    float get_change();
    vector<Item> shoppingCartItems;
private:
    float _totalSum;
    float _change;
};

#endif /* CUSTOMER_H */

