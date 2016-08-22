#ifndef VOTERDATA_H
#define VOTERDATA_H

#include "Data.h"
#include <iostream>
#include <vector>

class VoterData : public Data
{
public:
    /**
     * Reserve 100 empty element to prevent frequently reallocation on small data. 
     */
    VoterData() {_votersData.reserve(100);}
    ~VoterData() {};
    
    // Implement virtual functions
    void add_vote(const Voter &obj) override {_votersData.push_back(obj);}
    int get_size() override {return _votersData.size();}
    Voter &get_at_pos(int pos) override {return _votersData.at(pos);} // may used and return _votersData[pos];
private:
    std::vector<Voter> _votersData;
};

#endif /* VOTERDATA_H */