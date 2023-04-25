#include <stdio.h>

typedef struct BinarySearchTree
{
    BinarySearchTree* left;
    BinarySearchTree* right;
    int data;
} BinarySearchTree;

void isLeaf(BinarySearchTree* t)
{
    return (!(t->left || t->right))
}

void insert()
{

}

BinarySearchTree* remove(BinarySearchTree* t, int elem)
{
    if (t == NULL)
        return;
    
    if (t->data == elem)
    {
        if (isLeaf(tree))
        {
            free(t);
            return NULL;
        }

        BinarySearchTree* treeToReturn = NULL;

        if (t->right == NULL)
        {
            treeToReturn = t->left;
            while (treeToReturn != NULL)
                treeToReturn = treeToReturn->left;
        }
        else
        {
            treeToReturn = t->right;
            while (treeToReturn != NULL)
                treeToReturn = treeToReturn->right;
        }
        free(t);
        t = treeToReturn;
    }
    if (t->data > elem) 
        return remove(t->left, elem);
    return remove(t->right, elem);
}

void printCrescente(BinarySearchTree* t)
{
    if (t == NULL)
        return;
    printCrescente(t->left);
    prinf("%d", t->data);
    printCrescente(t->right);
}

void printDescrescente(BinarySearchTree* t)
{
    if (t == NULL)
        return;
    printDescrescente(t->right);
    prinf("%d", t->data);
    printDescrescente(t->left);
}