
#ifndef InventoryRecord_hpp
#define InventoryRecord_hpp

#include <iostream>

class InventoryRecord
{
public:
    InventoryRecord(int setID, std::string setType, int setNum);
    InventoryRecord();
    int getID() { return ID; }
    std::string getString() { return type; }
    int getNumItems() { return numItems; }
    void setID(int newID);
    void setString(std::string newType);
    void setNum(int newNum);


private:
    int ID;
    std::string type;
    int numItems;
};

#endif /* InventoryRecord_hpp */