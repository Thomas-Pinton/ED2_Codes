typedef struct BinarySearchTree
{
    BinarySearchTree* left;
    BinarySearchTree* right;
    int data;
} BinarySearchTree;

typedef struct AVLTree
{
    BinarySearchTree* left;
    BinarySearchTree* right;
    int data;
} AVLTree;

int isLeaf(BinarySearchTree* t)
{
    return (!(t->left || t->right));
}