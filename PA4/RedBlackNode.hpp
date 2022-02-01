#ifndef RedBlackNode_hpp
#define RedBlackNode_hpp

#include <iostream>
#include "InventoryRecord.hpp"
enum Color { RED, BLACK };

template <class T>
class RedBlackNode
{
public:
    RedBlackNode(T newData)
    { 
        data = newData;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = RED;
    }
    RedBlackNode()
    {
        data = NULL;
        this = NULL;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = RED;
    }
    T getData() { return data; }
    RedBlackNode* getLeft() { return left; }
    RedBlackNode* getRight() { return right; }
    RedBlackNode* getParent() { return parent; }
    bool getColor() { return color; }
    void setColor(bool a) { color = a; }
    void setLeft(RedBlackNode* a) { left = a; }
    void setRight(RedBlackNode* a) { right = a; }
    void setParent(RedBlackNode* a) { parent = a; }
    void setData(T newData) { data = newData; }
private: 

    T data;
    RedBlackNode* left;
    RedBlackNode* right;
    RedBlackNode* parent;
    bool color;
};

#endif /* RedBlackNode_hpp */