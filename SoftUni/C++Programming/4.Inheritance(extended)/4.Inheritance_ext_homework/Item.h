#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item();
    Item(string barcode, string productName, float price);
    Item(const Item &obj);
    Item& operator=(const Item &obj);
    virtual ~Item();

    void set_barcode(string barcode);
    void set_product_name(string productName);
    void set_price(float price);

    string get_barcode() const;
    string get_product_name() const;
    float get_price() const;

    friend float operator+=(float &totalSum, const Item &obj);
private :
    string _barcode;
    string _productName;
    float _price;
};

#endif /* ITEM_H */

