#include "InventoryRecord.hpp"



InventoryRecord::InventoryRecord(int setID, std::string setType, int setNum)
{
    ID = setID;
    type = setType;
    numItems = setNum;
}

InventoryRecord::InventoryRecord()
{
    ID = 0;
   
    numItems = 0;
}
void InventoryRecord::setID(int newID)
{
    ID = newID;
}
void InventoryRecord::setString(std::string newType)
{
    type = newType;
}
void InventoryRecord::setNum(int newNum)
{
    numItems = newNum;
}