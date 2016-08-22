#include "Collector.h"

/******************************************************************************/
// Public functions
/******************************************************************************/
map<int, int> Collector::result_base_on_age(int age)
{
    int stay = 0, leave = 0, size = collectorShareData->get_size();
    bool isFind = false;
    for (int i = 0; i < size; i++)
    {
        if (collectorShareData->get_at_pos(i).get_age() == age)
        {
            add_vote_info_based_on_current_voter(stay, leave, i);
            isFind = true;
        }
    }
    if (!isFind)
    {
        cout << "No match for " << age << endl;
        map<int, int> res;
        res[-1] = -1;
        return res;
    }
    map<int, int> result;
    result.insert(make_pair(stay, leave));
    return result;
}

map<int, int> Collector::result_base_on_name(string name)
{
    string(Collector::*funcPtr)(int index) = &Collector::get_name_in_pos;
    return result_base_user_param(name, funcPtr);
}

map<int, int> Collector::result_base_on_ethnos(string name)
{
    string(Collector::*funcPtr)(int index) = &Collector::get_ethnos_in_pos;
    return result_base_user_param(name, funcPtr);
}

map<int, int> Collector::result_base_on_city(string name)
{
    string(Collector::*funcPtr)(int index) = &Collector::get_city_in_pos;
    return result_base_user_param(name, funcPtr);
}

/******************************************************************************/
// Private functions
/******************************************************************************/
void Collector::add_vote_info_based_on_current_voter(int &posVote, int &negVote, int index)
{
    if (collectorShareData->get_at_pos(index).get_vote())
    {
        ++posVote;
    }
    else
    {
        ++negVote;
    }
}

map<int, int> Collector::result_base_user_param(string val, string(Collector::*func)(int index))
{
    int stay = 0, leave = 0, size = collectorShareData->get_size();
    bool isFind = false;
    for (int i = 0; i < size; i++)
    {
        if (val.compare((this->*func)(i)) == 0)
        {
            add_vote_info_based_on_current_voter(stay, leave, i);
            isFind = true;
        }
    }
    if (!isFind)
    {
        cout << "No match for " << val << endl;
        map<int, int> res;
        res[-1] = -1;
        return res;
    }
    map<int, int> result;
    result.insert(make_pair(stay, leave));
    return result;
}

map<float, float> Collector::result_based_in_percent()
{
    int stay = 0, leave = 0, size = collectorShareData->get_size();
    for (int i = 0; i < size; i++)
    {
        add_vote_info_based_on_current_voter(stay, leave, i);
    }
    // (stay / allvotes) * 100 result in percent
    float stayInPercent = 0, leaveInPercent = 0;
    if (stay == 0)
    {
        stayInPercent = 0.0f;
    }
    else
    {
        stayInPercent = (stay * 1.0F / size) * 100;
    }

    if (leave == 0)
    {
        leaveInPercent = 0.0f;
    }
    else
    {
        leaveInPercent = (leave * 1.0F / size) * 100;
    }
    map<float, float> resulInPrecent;
    resulInPrecent.insert(make_pair(stayInPercent, leaveInPercent));
    return resulInPrecent;
}

string Collector::get_name_in_pos(int index)
{
    return collectorShareData->get_at_pos(index).get_name();
}

string Collector::get_ethnos_in_pos(int index)
{
    return collectorShareData->get_at_pos(index).get_ethnos();
}

string Collector::get_city_in_pos(int index)
{
    return collectorShareData->get_at_pos(index).get_living_city();
}


// Old variant. Bad code :)!
/*
map<int, int> Collector::result_base_on_name(string name)
{
    int stay = 0, leave = 0, size = collectorShareData->get_size();
    for (int i = 0; i < size; i++)
    {
        if (name.compare(collectorShareData->get_at_pos(i).get_name()) == 0)
        {
            add_vote_info_based_on_current_voter(stay, leave, i);
        }
    }
    map<int, int> result;
    result.insert(make_pair(stay, leave));
    return result;
}

map<int, int> Collector::result_base_on_ethnos(string name)
{
    int stay = 0, leave = 0, size = collectorShareData->get_size();
    for (int i = 0; i < size; i++)
    {
        if (name.compare(collectorShareData->get_at_pos(i).get_ethnos()) == 0)
        {
            add_vote_info_based_on_current_voter(stay, leave, i);
        }
    }
    map<int, int> result;
    result.insert(make_pair(stay, leave));
    return result;
}

map<int, int> Collector::result_base_on_city(string name)
{
    int stay = 0, leave = 0, size = collectorShareData->get_size();
    for (int i = 0; i < size; i++)
    {
        if (name.compare(collectorShareData->get_at_pos(i).get_living_city()) == 0)
        {
            add_vote_info_based_on_current_voter(stay, leave, i);
        }
    }
    map<int, int> result;
    result.insert(make_pair(stay, leave));
    return result;
}
 */