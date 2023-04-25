#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

int search(BTree* t, int key)
{
    if (t == NULL)
        return NOT_FOUND;
    
    int i = 0;
    while(i < t->nodesAmount && key > t->keys[i])
    {
        i++;
    }
    
    if (i < t->nodesAmount && key == t->keys[i])
        return FOUND;

    return search(t->nodes[i], key);

}

BTree* insertion(BTree* t, int key)
{
    if (t == NULL)
        return;

    int i = 0;
    while(i < t->nodesAmount && key > t->keys[i])
    {
        i++;
    }
    
    if (!t->nodes[i]->isLeaf)
        return insertion(t->nodes[i], key);
    
    BTree* tProx = t->nodes[i];

    if (tProx->nodesAmount == (2 * T) - 1) // if it's full
    {
        if (t->nodesAmount == (2 * T) - 1)
        {
            printf("Nao sei resolver esse caso ainda");
        }
        BTree* tLeft = (BTree*) malloc(sizeof(BTree));
        BTree* tRight = (BTree*) malloc(sizeof(BTree));

        int j;
        for (j = 0; j < T-1; j++)
        {
            tLeft = tProx->nodes[j];
            tLeft = tProx->keys[j];
            tRight = tProx->nodes[j + T];
            tRight = tProx->keys[j + T];
        }

        tLeft = tProx->nodes[j];
        tRight = tProx->nodes[j + T];

        return;
    }
    
    int j = t->nodesAmount;
    while (j >= i)
    {
        t->keys[j+1] = t->keys[j];
        t->nodes[j+2] = t->nodes[j+1];
    }

    t->keys[i] = key;
    t->nodes[j+2] = NULL;

}

void printBTree(BTree* t)
{
    for (int i = 0; i < t->nodesAmount-1; i++)
    {
        printf("%d", t->keys[i]);
    }
    printf("\n");
    for (int i = 0; i < t->nodesAmount; i++)
    {
        printBTree(t->nodes[i]);
    }
    return;
}

int main()
{
    BTree* tree = (BTree*) malloc(sizeof(BTree));
    insertion(tree, 1);
    insertion(tree, 3);
    insertion(tree, 2);
    printBTree(tree);
    printf("Finished!");
}