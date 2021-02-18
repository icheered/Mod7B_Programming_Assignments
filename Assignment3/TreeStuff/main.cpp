#include "src/Tree.h"
#include "src/TreeNode.h"
#include <iostream>
#include <cstdlib>

//==============================================================
// Filename : main.cpp
// Authors :  Tjeerd Bakker and Soenke van Loh
// Version :
// License :
// Description :
//==============================================================

class Entity
{
public:
    int data;
};

int main()
{
    //Predefined list of integers
    int randarray[7] = { 9, 10, 8, 12, 7, 13, 11};

    // Class instance from template of type integer
    Tree<int> tree;

    //Iterator: For each entity in `randarray` do the following:
    for (auto &ref : randarray) {
        tree.insertNode(ref);
    }

    int userInput;
    std::cout << "Enter a number: ";
    std::cin >> userInput;

    TreeNode<int>* node = tree.search(userInput);

    if(node == nullptr)
    {
        std::cout << userInput << " Is not in tree" << std::endl;
    }
    else {
        std::cout << userInput << " Is in tree" << std::endl;
    }

    // Print the tree vertically
    std::cout << "Printing the tree vertically" << std::endl;
    tree.printTree();


    return 0;
}
