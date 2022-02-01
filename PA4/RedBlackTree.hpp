#ifndef RedBlackTree_hpp
#define RedBlackTree_hpp
#include <algorithm>  
#include "RedBlackNode.hpp"



template <class T>
class RedBlackTree
{
public:
    RedBlackTree() { root = NULL; }
    int isEmpty(T* node) //Returns 1 if empty and 0 if not
    {
        if (node == NULL)
            return 1;

        return 0;
    }
    T* insert(T *node, T* newNode)
    {
        //Returns the node to as the root if it is the first value
        if (isEmpty(node))
            return newNode;

        //Recursively go down the tree till an empty node is reached in a correct position
        if (newNode->getData().getID() < node->getData().getID())
        {
            node->setLeft(insert(node->getLeft(), newNode));
            node->getLeft()->setParent(node);
        }
        else if (newNode->getData().getID() > node->getData().getID())
        {
            node->setRight(insert(node->getRight(), newNode));
            node->getRight()->setParent(node);
        }

        
        return node;
    }
    void remove(T* node, int ID)
    {
        if (node == NULL)
        {
            
        }
        else if (node->getData().getID() == ID)
        {
            if ((node->getRight() != NULL && node->getLeft() != NULL) && node->getData().getID() < node->getParent()->getData().getID())
            {

                node->getLeft()->setRight(node->getRight());
                node->getParent()->setLeft(node->getLeft());
            }
            else if(node->getRight() != NULL && node->getLeft() != NULL)
            {
                node->getRight()->setLeft(node->getLeft());
                node->getParent()->setRight(node->getRight());
            }

            delete node;
        }

        else
        {
            remove(node->getLeft(), ID);
            remove(node->getRight(), ID);
        }
    }

    void removeHelp(int ID)
    {
        T* newNode;
        remove(root, ID);
        if (root->getData().getID() < ID)
        {
             newNode = root;
            while (newNode->getLeft() != NULL)
                newNode = newNode->getLeft();
        }
        else
        {
            newNode = root;
            while (newNode->getRight() != NULL)
                newNode = newNode->getRight();
        }
        fixViolation(root, newNode);
    }


    void printInOrder(T* node)
    {
        if (node == NULL)
            return;
        
        printInOrder(node->getLeft());

        std::cout << node->getData().getID() << " " << node->getData().getString() << " " << node->getData().getNumItems() << std::endl;

        printInOrder(node->getRight());
    }

    void rotateLeft(T*& node, T*& newNode) //Rotates tree or sub tree left
    {
        T* rightNode = newNode->getRight();
        newNode->setRight(rightNode->getLeft());

        if (newNode->getRight() != NULL)
            newNode->getRight()->setParent(newNode);

        rightNode->setParent(newNode->getParent());

        if (newNode->getParent() == NULL)
            root = rightNode;

        else if (newNode == newNode->getParent()->getLeft())
            newNode->getParent()->setLeft(rightNode);

        else
            newNode->getParent()->setRight(rightNode);

        rightNode->setLeft(newNode);
        newNode->setParent(rightNode);
    
    }

    void rotateRight(T*& node, T*& newNode) //Rotates tree or sub tree right
    {
        T* leftNode = newNode->getLeft();

        newNode->setLeft(leftNode->getRight());

        if (newNode->getLeft() != NULL)
            newNode->getLeft()->setParent(newNode);

        leftNode->setParent(newNode->getParent());

        if (newNode->getParent() == NULL)
            root = leftNode;

        else if (newNode == newNode->getParent()->getLeft())
            newNode->getParent()->setLeft(leftNode);

        else
            newNode->getParent()->setRight(leftNode);
        leftNode->setRight(newNode);
        newNode->setParent(leftNode);
    }

    void fixViolation(T*& node, T*& newNode)
    {
        T* parentNode = NULL;
        T* grandParentNode = NULL;

        while ((newNode != node) && (newNode->getColor() != BLACK) && (newNode->getParent()->getColor() == RED))
        {

            parentNode = newNode->getParent();
            grandParentNode = newNode->getParent()->getParent();


            //If the parent node ptr is left of grandparent this case is used
            if (parentNode == grandParentNode->getLeft())
            {

                T* uncle_pt = grandParentNode->getRight();

                //Uncle is red and only recoloring is needed
                if (uncle_pt != NULL && uncle_pt->getColor() ==
                    RED)
                {
                    grandParentNode->setColor(RED);
                    parentNode->setColor(BLACK);
                    uncle_pt->setColor(BLACK);
                    newNode = grandParentNode;
                }

                else
                {

                    //newNode is right of its parent so left rotation 
                    if (newNode == parentNode->getRight())
                    {
                        rotateLeft(root, parentNode);
                        newNode = parentNode;
                        parentNode = newNode->getParent();
                    }

                    //newNode is left of its parent so right rotation
                    rotateRight(root, grandParentNode);
                    bool temp = parentNode->getColor();
                    parentNode->setColor(grandParentNode->getColor());
                    grandParentNode->setColor(temp);
                    newNode = parentNode;
                }
            }

            //If parent ptr is right of grandparent then this is used
            else
            {
                T* uncle_pt = grandParentNode->getLeft();

                //Uncle is red so only need to recolor
                if ((uncle_pt != NULL) && (uncle_pt->getColor() ==
                    RED))
                {
                    grandParentNode->setColor(RED);
                    parentNode->setColor(BLACK);
                    uncle_pt->setColor(BLACK);
                    newNode = grandParentNode;
                }
                else
                {
                    //newNode is left of parent so right rotate
                    if (newNode == parentNode->getLeft())
                    {
                        rotateRight(root, parentNode);
                        newNode = parentNode;
                        parentNode = newNode->getParent();
                    }

                   //newNode is right of parent so left rotate
                    rotateLeft(node, grandParentNode);
                    bool temp = parentNode->getColor();
                    parentNode->setColor(grandParentNode->getColor());
                    grandParentNode->setColor(temp);
                    newNode = parentNode;
                }
            }
        }

        node->setColor(BLACK);
    }

    void insertHelp(T* newData) //Function to help with insertion (Inserts new node and fixes any violations)
    {

        root = insert(getRoot(), newData);

        fixViolation(root, newData);
    }

    int checkCollision(T* node, int ID, bool* flag)
    {
       

        if (node == NULL)
            return 0;
        
        checkCollision(node->getLeft(), ID, flag);

        if (ID == node->getData().getID())
        {
            *flag = true;
            return 1;
        }

        checkCollision(node->getRight(), ID, flag);
        return 0;
    }
    void findNode(T* node, InventoryRecord newRecord, int ID)
    {
        if (node == NULL)
        {

        }
        else if (node->getData().getID() == ID)
        {
       
            node->setData(newRecord);
        }

        else
        {
            findNode(node->getLeft(), newRecord, ID);
            findNode(node->getRight(), newRecord, ID);
        }
        
    }

    void clear(T* node)
    {
        if (node == NULL)
        {
            return;
        }
        clear(node->getLeft());
       clear(node->getRight());
       delete node;
        

    }

    T* getRoot()
    {
        return root;
    }

private:
    T* root;
};

#endif /* RedBlackTree_hpp */