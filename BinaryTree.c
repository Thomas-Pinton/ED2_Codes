#include <stdio.h>

typedef struct {
	char data;
	BinaryTree* left;
	BinaryTree* right;
} BinaryTree;

BinaryTree* createEmptyTree()
{
	return NULL;
}

BinaryTree* createTree(char d, BinaryTree* l, BinaryTree* r)
{
	BinaryTree* t = (BinaryTree*)malloc(sizeOf(BinaryTree));
	t->data = d;
	t->left = l;
	t->right = r;
	return t;
}

void deleteTree(BinaryTree* t)
{
	if (t != NULL)
	{
		deleteTree(t->right);
		deleteTree(t->left);
		free(t);
	}
}

typedef struct {
	char data;
	Tree* childs;
} Tree;

int belongsToTree(BinaryTree* a, char c)
{
	if (a == NULL)
		return 0;
	// caso base

	if (a->data == c)
		return 1;
	
	int left = belongsToTree(a->left, c);
	int right = belongsToTree(a->right, c);

	if (left || right)
		return 1;
	
	return 0;
}

int countNodes(BinaryTree* t)
{
	if (t == NULL)
		return 0;
	return (countNodes(t->left) + countNodes(t->right) + 1);
}

int calculateHeight(BinaryTree* t)
{
	if (t == NULL)
		return -1;
	int heightLeft = calculateHeight(t->left);
	int heightRight = calculateHeight(t->right);
	return ((heightLeft > heightRight) ? heightLeft + 1 : heightRight + 1);
}

int countLeafs(BinaryTree* t)
{
	if (t == NULL)
		return 0;
	if (t->left == NULL && t->right == NULL)
		return 1;
	return (countLeafs(t->left) + countLeafs(t->right));
}

int main()
{

}


