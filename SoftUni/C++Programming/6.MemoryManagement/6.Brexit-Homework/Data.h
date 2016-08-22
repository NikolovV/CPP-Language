#ifndef DATA_H
#define DATA_H

#include "Voter.h"

/**
 * Abstract class to specify data type (best for array or vector)
 */
class Data
{
public:
    virtual ~Data() {};
    /**
     * Add vote to database.
     * @param obj - current instance of Voter
     */
    virtual void add_vote(const Voter &obj) = 0;
    /**
     * @return - current size of database.
     */
    virtual int get_size() = 0;
    /**
     * Get reference to current position of database type.
     * (special for array and vector)
     * @param pos - current position in array or vector.
     * @return - reference on current object of type Voter.
     */
    virtual Voter &get_at_pos(int pos) = 0;
};

#endif /* DATA_H */