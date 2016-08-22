#include "Women.hpp"

Women::Women()
{
}

Women::~Women()
{
}

Women &Women::operator=(Man &aMan)
{
    this->bankAccount.balance = aMan.bankAccount.balance;
    aMan.bankAccount.balance = 0;
    return *this;
}

void Women::waste_money()
{
    this->bankAccount.balance = 0;
}