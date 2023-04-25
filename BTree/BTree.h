#define FOUND 1
#define NOT_FOUND 0

#define T 3
// t is the min amount of nodes

typedef struct BTree BTree;

struct BTree
{
    int keys[(2 * T) - 1];
    BTree* nodes[2*T];
    int isLeaf; // boolean
    int nodesAmount;
};