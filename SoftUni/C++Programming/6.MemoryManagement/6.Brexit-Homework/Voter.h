#ifndef VOTER_H
#define VOTER_H

#include "Person.h"

/**
 * Instance of Person and add private argument vote.
 */
class Voter : public Person
{
public:
    Voter() {};
    Voter(std::string name, unsigned int age, Gender gender, 
    std::string livingCity, std::string ethnos, bool vote) :
    Person(name, age, gender, livingCity, ethnos), _vote(vote) {};   
    ~Voter() {};
    
    // Getters
    std::string get_name() const {return _name;}
    unsigned int get_age() const {return _age;}
    Gender get_gender() const {return _gender;}
    std::string get_living_city() const {return _livingCity;}
    std::string get_ethnos() const {return _ethnos;}
    bool get_vote() const {return _vote;}
    
private:
    bool _vote; // 0 leave, 1 stay
};


#endif /* VOTER_H */