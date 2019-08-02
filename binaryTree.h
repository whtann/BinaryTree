#include <iostream>

using namespace std;

struct btnode
{
    int data;
    btnode *l;
    btnode *r;
};

class binaryTree
{
private:
    btnode *root;
    void insert(int key, btnode *leaf);
    void deleteTree(btnode *leaf);

public:
    binaryTree();
    ~binaryTree();
    void insert(int key);
    void deleteTree();
    btnode *search(int key, btnode *leaf);
    void inOrderPrint(btnode *leaf);
};