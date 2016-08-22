#include <iostream>

#include "ControlData.h"


void ControlData::remove_from_list_by_id(unsigned int &ID)
{
    std::list<ShopList>::iterator it;
    for(it = items.begin(); it != items.end(); it++)
    {
        if (*it == ID)
        {
            items.erase(it);
        }
    }
}

void ControlData::print_list()
{
    for (auto elem : items)
    {
        std::cout << elem.get_ID() << " - " << elem.get_name() << std::endl;
    }
}