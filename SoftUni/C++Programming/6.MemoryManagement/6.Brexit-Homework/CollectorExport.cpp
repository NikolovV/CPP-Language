#include "CollectorExport.h"

/******************************************************************************/
// Public functions
/******************************************************************************/
std::set<int> CollectorExport::all_possible_age()
{
    int (CollectorExport::*funcPtr)(int) = &CollectorExport::age_in_pos;
    return all_possible_for<int>(funcPtr);
}

std::set<std::string> CollectorExport::all_possible_name()
{
    std::string(CollectorExport::*funcPtr)(int) = &CollectorExport::name_in_pos;
    return all_possible_for<std::string>(funcPtr);
}

std::set<std::string> CollectorExport::all_possible_ethnos()
{
    std::string(CollectorExport::*funcPtr)(int) = &CollectorExport::ethnos_in_pos;
    return all_possible_for<std::string>(funcPtr);
}

std::set<std::string> CollectorExport::all_possible_city()
{
    std::string(CollectorExport::*funcPtr)(int) = &CollectorExport::city_in_pos;
    return all_possible_for<std::string>(funcPtr);
}

/******************************************************************************/
// Private functions
/******************************************************************************/
template<typename T>
std::set<T> CollectorExport::all_possible_for(T(CollectorExport::*funcPtr)(int index))
{
    int size = _collectorExport->get_size();
    std::set<T> result;
    for (int i = 0; i < size; ++i)
    {
        result.insert((this->*funcPtr)(i));
    }
    return result;
}

int CollectorExport::age_in_pos(int index)
{
    return _collectorExport->get_at_pos(index).get_age();
}

std::string CollectorExport::name_in_pos(int index)
{
    return _collectorExport->get_at_pos(index).get_name();
}

std::string CollectorExport::ethnos_in_pos(int index)
{
    return _collectorExport->get_at_pos(index).get_ethnos();
}

std::string CollectorExport::city_in_pos(int index)
{
    return _collectorExport->get_at_pos(index).get_living_city();
}