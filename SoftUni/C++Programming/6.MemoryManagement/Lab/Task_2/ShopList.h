#ifndef SHOPLIST_H
#define SHOPLIST_H

class ShopList
{
public:
    ShopList(){};
    ShopList(unsigned int ID, std::string name) : _ID(ID), _itemName(name) {};
    virtual ~ShopList() {};
    bool operator==(const unsigned int &id) {if(this->_ID == id){return true;} return false;}
    
    void set_ID(unsigned int ID) {this->_ID = ID;}
    void set_name(std::string name) {this->_itemName = name;}
    
    unsigned int get_ID() const {return this->_ID;}
    std::string get_name() const {return this->_itemName;}
private:
    unsigned int _ID;
    std::string _itemName;
};

#endif /* SHOPLIST_H */