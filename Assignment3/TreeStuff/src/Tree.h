// Fig. 19.22: Tree.h
// Template Tree class definition.

//==============================================================
// Filename : Tree.h
// Authors :  Tjeerd Bakker and Soenke van Loh
// Version :
// License :
// Description :
//==============================================================



#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include <iostream>
#include <string>

// Tree class-template definition
template <typename NODETYPE> class Tree
{
  public:
    // constructor
    Tree() : rootPtr(nullptr) { /* empty body */}

    // insert node in Tree
    void insertNode(const NODETYPE &value)
    {
        insertNodeHelper(&rootPtr, value);
    } // end function insertNode

    // begin preorder traversal of Tree
    void preOrderTraversal() const
    {
        preOrderHelper(rootPtr);
    } // end function preOrderTraversal

    // begin inorder traversal of Tree
    void inOrderTraversal() const
    {
        inOrderHelper(rootPtr);
    } // end function inOrderTraversal

    // begin postorder traversal of Tree
    void postOrderTraversal() const
    {
        postOrderHelper(rootPtr);
    } // end function postOrderTraversal

    TreeNode<NODETYPE>* search(NODETYPE value)
    {
        return searchHelper(&rootPtr, value);
    }

    void printTree() const
    {
        printTreeHelper(rootPtr, 0);
    }


  private:
    TreeNode<NODETYPE> *rootPtr;


    // Perform a binary search
    TreeNode<NODETYPE>* searchHelper(TreeNode<NODETYPE> **ptr, NODETYPE value)
    {  
        if (*ptr == nullptr){
            return nullptr;
        }
        else{
            // Check if the current node has the desired value
            if(value == (*ptr)->data){
                return *ptr;
            }

            // If the desired value is smaller than the value of the current node, go to the left node
            else if(value < (*ptr)->data){
                return searchHelper(&((*ptr)->leftPtr), value);
            }
            // If the desired value is larger than the value of the current node, go to the right node
            else if(value > (*ptr)->data){
                return searchHelper(&((*ptr)->rightPtr), value);
            }
            else {
                return nullptr;
            }
        }
    }


    void printTreeHelper(TreeNode<NODETYPE> *ptr, int depth) const
    {

        // If right node is not a nullpointer
            // Go into right node with increased depth
        if(ptr->rightPtr != nullptr){
            printTreeHelper(ptr->rightPtr, depth + 1);
        }

        // Print own number
        for(int i = depth; i > 0; i--)
        {
            std::cout << "  ";
        }
        std::cout << ptr->getData() << std::endl;


        // If left node is not a nullpointer
            // Go into left node with increased depth
        if(ptr->leftPtr != nullptr){
            printTreeHelper(ptr->leftPtr, depth + 1);
        }
        return;
    }






    // utility function called by insertNode; receives a pointer
    // to a pointer so that the function can modify pointer's value
    void insertNodeHelper(TreeNode<NODETYPE> **ptr, const NODETYPE &value)
    {
        // subtree is empty; create new TreeNode containing value
        if (*ptr == nullptr)
            *ptr = new TreeNode<NODETYPE>(value);
        else // subtree is not empty
        {
            // data to insert is less than data in current node
            if (value < (*ptr)->data)
                insertNodeHelper(&((*ptr)->leftPtr), value);
            else {
                // data to insert is greater than data in current node
                if (value > (*ptr)->data)
                    insertNodeHelper(&((*ptr)->rightPtr), value);
                else // duplicate data value ignored
                    std::cout << value << " dup" << std::endl;
            } // end else
        }     // end else
    }         // end function insertNodeHelper

    // utility function to perform preorder traversal of Tree
    void preOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr) {
            std::cout << ptr->data << ' '; // process node
            preOrderHelper(ptr->leftPtr);  // traverse left subtree
            preOrderHelper(ptr->rightPtr); // traverse right subtree
        }                                  // end if
    }                                      // end function preOrderHelper

    // utility function to perform inorder traversal of Tree
    void inOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr) {
            inOrderHelper(ptr->leftPtr);   // traverse left subtree
            std::cout << ptr->data << ' '; // process node
            inOrderHelper(ptr->rightPtr);  // traverse right subtree
        }                                  // end if
    }                                      // end function inOrderHelper

    // utility function to perform postorder traversal of Tree
    void postOrderHelper(TreeNode<NODETYPE> *ptr) const
    {
        if (ptr != nullptr) {
            postOrderHelper(ptr->leftPtr);  // traverse left subtree
            postOrderHelper(ptr->rightPtr); // traverse right subtree
            std::cout << ptr->data << ' ';  // process node
        }                                   // end if
    }                                       // end function postOrderHelper
};                                          // end class Tree

#endif

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
