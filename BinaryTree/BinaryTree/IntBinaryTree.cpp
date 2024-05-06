/*
 *
 * Celine Wang
 *
 * Implementation file for IntBinaryTree class
 * of Chapter 21, Programming BinaryTree
 *
 * May 2024
 *
 */

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

// ********************************************************
// name:      insert
// called by: IntBinaryTree::insertNode
// passed:    TreeNode* &, TreeNode* &
// returns:   nothing
// calls:     (Recursive)
// The insert function insert the node into the tree      *
// pointed to by the TreeNode pointer                     *
// ********************************************************
void IntBinaryTree::insert(TreeNode* &nodePtr, TreeNode* &newNode) {
    if (nodePtr == nullptr) {
        nodePtr = newNode;                  // Insert the node
    }
    else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode);     // Search the left branch
    }
    else {
        insert(nodePtr->right, newNode);    // Search the right branch
    }
}

// ********************************************************
// name:      insertNode
// called by: insertInteger
// passed:    int
// returns:   nothing
// calls:     IntBinaryTree::insert
// The insertNode function creates a new node to hold num *
// as its value, and passes it to the insert function     *
// ********************************************************
void IntBinaryTree::insertNode(int num) {
    TreeNode* newNode = nullptr;          // Pointer to a new node
    
    // Create a new node and store num in it
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;
    
    // Insert the node
    insert(root, newNode);
}

// ********************************************************
// name:      destroySubTree
// called by: ~IntBinaryTree()
// passed:    TreeNode*
// returns:   nothing
// calls:     (Recursive)
// The destroySubTree function deletes all nodes int the  *
// tree                                                   *
// ********************************************************
void IntBinaryTree::destroySubTree(TreeNode* nodePtr) {
    if (nodePtr) {
        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }
        else if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr;
    }
}

// ********************************************************
// name:      displayInOrder
// called by: IntBinaryTree::displayInOrder()
// passed:    TreeNode*
// returns:   nothing
// calls:     (Recursive)
// The displayInOrder function display the values in the  *
// subtree pointed by nodePtr, via inorder traversal      *
// ********************************************************
void IntBinaryTree::displayInOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

// ********************************************************
// name:      getLeafCount
// called by: IntBinaryTree::displayLeafCount()
// passed:    TreeNode*
// returns:   int
// calls:     (Recursive)
// The getLeafCount function get the number of leaf nodes *
// in the tree                                            *
// ********************************************************
int IntBinaryTree::getLeafCount(TreeNode* nodePtr) const {
    if (nodePtr) {
        if (nodePtr->left && nodePtr->right) {    // Both left and right nodes exist
            return getLeafCount(nodePtr->left) + getLeafCount(nodePtr->right);
        }
        else if (nodePtr->left) {     // Only left node exists
            return getLeafCount(nodePtr->left);
        }
        else if (nodePtr->right) {    // Only right node exists
            return getLeafCount(nodePtr->right);
        }
        else {                        // No child node exists
            return 1;
        }
    }
    // Node does not exist
    else {
        return 0;
    }
}

// ********************************************************
// name:      getTreeHeight
// called by: IntBinaryTree::displayTreeHeight()
// passed:    TreeNode*
// returns:   int
// calls:     (Recursive)
// The getTreeHeight function get the length of path from *
// the root to the deepest node in the tree               *
// ********************************************************
int IntBinaryTree::getTreeHeight(TreeNode* nodePtr) const {
    if (!nodePtr) { // node does not exist
        return 0;
    }
    else {          // node exists
        if (!nodePtr->left && !nodePtr->right) { // No child nodes
            return 0;
        }
        else {      // At least one child exists, add one level
            return max(getTreeHeight(nodePtr->left), getTreeHeight(nodePtr->right)) + 1;
        }
    }
}

// ********************************************************
// name:      getTreeWidth
// called by: IntBinaryTree::displayTreeWidth
// passed:    TreeNode*
// returns:   int
// calls:     (Recursive)
// The getTreeWidth function get the largest number of    *
// nodes in the same level of the tree                    *
// ********************************************************
int IntBinaryTree::getTreeWidth(TreeNode* nodePtr) const {
    int maxWidth = 0;
    if (!nodePtr) {      // Empty tree
        return 0;
    }
    else {
        int height = getTreeHeight(nodePtr);         // Get the height(max level) of the tree
        for (int level = 0; level < height; level++ ) {
            int width = getWidthAtLevel(nodePtr, level);
            maxWidth = max(maxWidth, width);      // Compare width at current level with maxWidth from previous levels
        }
        return maxWidth;
    }
}

// ********************************************************
// name:      getWidthAtLevel
// called by: IntBinaryTree::getTreeWidth
// passed:    TreeNode*, int
// returns:   int
// calls:     (Recursive)
// The getWidthAtLevel function get the number of nodes   *
// at specific level of the tree                          *
// ********************************************************
int IntBinaryTree::getWidthAtLevel(TreeNode* nodePtr, int level) const {
    if (!nodePtr) {      // nodePtr base case: Node doesn't exist
        return 0;
    }
    if (level == 0) {    // Level base case: To the target level
        return 1;
    }
    // Calculate the width at the next level for the left and right subtrees
    return getWidthAtLevel(nodePtr->left, level - 1) + getWidthAtLevel(nodePtr->right, level - 1);
}

