/*
 *
 * Celine Wang
 *
 * Specification(Header) file for IntBinaryTree class
 * of Chapter 21, Programming BinaryTree
 *
 * May 2024
 *
 */

#ifndef IntBinaryTree_h
#define IntBinaryTree_h

class IntBinaryTree {
private:
    struct TreeNode {
        int value;                // The value in the node
        TreeNode* left;           // Pointer to the left child node
        TreeNode* right;          // Pointer to the right child node
    };
    
    TreeNode* root;
    
    // Private member functions
    void insert(TreeNode* &, TreeNode* &);
    void destroySubTree(TreeNode*);
    void displayInOrder(TreeNode*) const;
    int getLeafCount(TreeNode*) const;
    int getTreeHeight(TreeNode*) const;
    int getTreeWidth(TreeNode*) const;
    int getWidthAtLevel(TreeNode*, int) const;
    
public:
    //Constructor
    IntBinaryTree(){ root = nullptr; }
    
    // Destructor
    ~IntBinaryTree(){ destroySubTree(root); }
    
    // Binary tree operations
    void insertNode(int);
    void displayInOrder() const { displayInOrder(root); }
    
    void displayLeafCount() const {
        std::cout<< "Leaf Count: " << getLeafCount(root) << std::endl; }
    void displayTreeHeight() const {
        std::cout<< "Tree Height: " << getTreeHeight(root) << std::endl;  }
    void displayTreeWidth() const {
        std::cout<< "Tree Width: " << getTreeWidth(root) << std::endl; }
};
#endif /* IntBinaryTree_h */
