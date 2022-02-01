/*
Sage Kreiter
PA4
Due 10/30/2020
*/

//Big-O for insertion: O(logn) because it can find where it needs to be inserted easily since the tree is a BST
//Big-O for remove: O(logn) same as insertion since it can find the item quickly
//Big-O for clear: O(n) because it has to go to every node and delete each





#include <iostream>
#include <fstream>
#include <string>
#include "RedBlackTree.hpp"
#include "InventoryRecord.hpp"

int main()
{
    int choice = 0;
    bool flag = 0;
    RedBlackTree<RedBlackNode<InventoryRecord>> tree;
    std::ifstream infile;
    infile.open("Inventory.csv");
    while (!infile.eof())
    {
        std::string a, b, c;
        getline(infile, a, ',');
        getline(infile, b, ',');
        getline(infile, c);
        int d = std::stoi(a);
        int e = std::stoi(c);
        InventoryRecord* newRecord = new InventoryRecord(d, b, e);
        RedBlackNode<InventoryRecord>* newNode = new RedBlackNode<InventoryRecord>(*newRecord);
        tree.insertHelp(newNode);
    }
    infile.close();


    while (choice != 5) //While loop to run the menu till user chooses to exit
    {
        system("cls");
        std::cout << "1. Add item\n2. Remove item\n3. Update Item\n4. Display Inventory\n5. Exit\nEnter your choice: ";
        std::cin >> choice;
        std::cout << "\n\n";


        if (choice == 1) //Add value
        {
            int newID = 0, numItems = 0;
            std::string newItem;
            std::cout << "What is the ID of the item you are adding(int): ";
            std::cin >> newID;
            std::cout << "What is the type of item you are adding(string): ";
            std::cin >> newItem;
            std::cout << "How many are in the inventory(int): ";
            std::cin >> numItems;


            //Checking if the ID entered has already been used so errors don't occur
            flag = 0;
            tree.checkCollision(tree.getRoot(), newID, &flag);
            if (flag != 1)
            {
                InventoryRecord* newRecord = new InventoryRecord(newID, newItem, numItems);
                RedBlackNode<InventoryRecord>* newNode = new RedBlackNode<InventoryRecord>(*newRecord);
                tree.insertHelp(newNode);
            }
            else
            {
                std::cout << "Sorry that ID has already been used.\n";
                char trash;
                std::cout << "\nEnter and char to continue";
                std::cin >> trash;
            }
        }

        else if(choice == 2)// Remove Value
        {
            std::cout << "Enter ID of item you want to remove(int): ";
            int remover = 0;
            std::cin >> remover;
            //Checking if value exists
            flag = 0;
            tree.checkCollision(tree.getRoot(), remover, &flag);
            if (flag == true)
            {
                tree.removeHelp(remover);
            }
            else
            {
                std::cout << "Could not find ID\n";
                char trash;
                std::cout << "\nEnter and char to continue";
                std::cin >> trash;
            }
        }

        else if (choice == 3)
        {
            std::cout << "Enter ID of what you'd like to update: ";
            int thing, newNum;
            std::string newString;
            std::cin >> thing;

            std::cout << "New type: ";
            std::cin >> newString;
            std::cout << "New amount: ";
            std::cin >> newNum;
            InventoryRecord newRecord(thing, newString, newNum);
            tree.findNode(tree.getRoot(), newRecord, thing);
        }

        else if (choice == 4)
        {
            tree.printInOrder(tree.getRoot());
            char trash;
            std::cout << "\nEnter and char to continue";
            std::cin >> trash;
        }
    }


    tree.clear(tree.getRoot());
    return 0;
}