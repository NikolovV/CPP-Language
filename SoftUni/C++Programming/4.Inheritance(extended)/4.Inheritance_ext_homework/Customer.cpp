#include "Customer.h"

Customer::Customer() : _totalSum(0.0), shoppingCartItems(0), _change(0.0)
{
}

Customer::~Customer()
{
}

void Customer::add_to_invoice(const Item &item)
{
    shoppingCartItems.push_back(item);
}

void Customer::clear_invoice()
{
    this->shoppingCartItems.erase(shoppingCartItems.begin(),
                                  shoppingCartItems.end());
    this->_totalSum = 0.0;
}

void Customer::set_total(float total)
{
    this->_totalSum = total;
}

void Customer::set_change()
{
    if (_totalSum == 0.0)
    {
        cout << "No item." << endl;
        return ;
    }
    cout << "Please enter the amount of money: ";
    float amountOfMoney;
    cin >> amountOfMoney;
    if (amountOfMoney < _totalSum)
    {
        cout << "Need more money." << endl;
        return;
    }
    this->_change = amountOfMoney - _totalSum;
}

float Customer::get_total() const
{
    return _totalSum;
}

float Customer::get_change()
{
    return _change;
}