#ifndef COLLECTOR_H
#define COLLECTOR_H

#include "CollectorControl.h"
#include "Data.h"

class Collector : public CollectorControl
{
public:
    Collector(std::shared_ptr<Data> newShareData) {collectorShareData = newShareData;}
    virtual ~Collector() {};
    
    // Return map<> type - Leave - Stay based on condition.
    map<float, float> result_based_in_percent() override;
    map<int, int> result_base_on_age(int age) override;
    map<int, int> result_base_on_name(string name) override;
    map<int, int> result_base_on_ethnos(string name) override;
    map<int, int> result_base_on_city(string name) override;
    
private:
    /**
     * Increment positive or negative vote based on current voter.
     * @param posVote - positive vote (1)
     * @param negVote - negative vote (0)
     * @param index - current index (for vector and array index)
     */
    void add_vote_info_based_on_current_voter(int &posVote, int &negVote, int index);
    
    /**
     * Call corresponding function as pointer to function, base on user choice.
     * @param val - user input string.
     * @param func - take pointer to function that take int index position.
     * @return - map<> type base on val and function pointer.
     */
    map<int, int> result_base_user_param(string val, string (Collector::*func)(int index));
    
    /**
     * Used to be call from pointer to function for compare parameters.
     * @param index - current index
     * @return - string to the variable at index.
     */
    string get_name_in_pos(int index);
    string get_ethnos_in_pos(int index);
    string get_city_in_pos(int index);
    
    std::shared_ptr<Data> collectorShareData;
};

#endif /* COLLECTOR_H */