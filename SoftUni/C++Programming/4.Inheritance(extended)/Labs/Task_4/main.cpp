#include <iostream>

#include "Man.hpp"
#include "Women.hpp"

using namespace std;
void add_money_to_mans_card(float amount, Man &aMan);

int main()
{
    Man gosho = Man();
    add_money_to_mans_card(2000, gosho);
    
    Women penka;
    penka = gosho;
    penka.waste_money();

    return 0;
}

void add_money_to_mans_card(float amount, Man &aMan)
{
    aMan.bankAccount.balance += amount;
}
