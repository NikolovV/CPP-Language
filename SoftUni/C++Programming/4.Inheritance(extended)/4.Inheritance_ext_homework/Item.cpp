#include "Item.h"
#include "MenuOption.h"

Item::Item() : _barcode("0"), _productName("n/a"), _price(0.0)
{
}

Item::Item(string barcode, string productName, float price)
{
    set_barcode(barcode);
    set_product_name(productName);
    set_price(price);
}

// copy constructor

Item::Item(const Item &obj) : _barcode(obj._barcode), _productName(obj._productName),
_price(obj._price)
{
#if DEBUG
    cout << "Copy constructor call." << std::endl;
#endif
}

Item& Item::operator=(const Item &obj)
{
#if DEBUG
    cout << "operator = call" << endl;
#endif
    if (this == &obj)
    {
        return *this;
    }
    this->_barcode = obj._barcode;
    this->_productName = obj._productName;
    this->_price = obj._price;

    return *this;
}

Item::~Item()
{
}

void Item::set_barcode(string barcode)
{
    this->_barcode = barcode;
}

void Item::set_product_name(string productName)
{
    this->_productName = productName;
}

void Item::set_price(float price)
{
    this->_price = price;
}

string Item::get_barcode() const
{
    return _barcode;
}

string Item::get_product_name() const
{
    return _productName;
}

float Item::get_price() const
{
    return _price;
}