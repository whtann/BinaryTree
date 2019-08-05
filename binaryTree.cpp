#include "binaryTree.h"
#include <queue>

int main()
{
    binaryTree myTree;
    int choice;
    while (1)
    {
        //menu
        cout << "BINARY TREE" << endl
             << "MENU" << endl
             << "---------------" << endl;
        cout << "1. Insert element" << endl
             << "2. Delete tree" << endl
             << "3. Display tree" << endl
             << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        //check for bad input
        if (!cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter a number" << endl
                 << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                int key;
                cout << "Enter value to insert: ";
                cin >> key;
                myTree.insert(key);
                cout << endl;
                break;
            case 2:
                myTree.deleteTree();
                cout << "Tree Deleted" << endl;
                break;
            case 3:
                myTree.printTree();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Not A Choice" << endl
                     << endl;
                break;
            }
        }
    }
    return 0;
}

//default constructor
binaryTree::binaryTree()
{
    root = nullptr;
}

//destructor that calls recusive function for deleting the tree
binaryTree::~binaryTree()
{
    deleteTree(root);
}

//public member function that allows deletion of the entire tree
void binaryTree::deleteTree()
{
    deleteTree(root);
}

//recursive function for deleting tree
void binaryTree::deleteTree(btnode *leaf)
{
    if (leaf)
    {
        deleteTree(leaf->l);
        deleteTree(leaf->r);
        delete leaf;
    }
}

//public member function that allows for insertion of data into the tree
void binaryTree::insert(int key)
{
    insert(key, root);
}

//recursive function that inserts nodes in the tree
void binaryTree::insert(int key, btnode *leaf)
{
    if (!root)
    {
        root = new btnode;
        root->data = key;
        root->l = root->r = nullptr;
    }
    else
    {
        if (key < leaf->data)
        {
            if (leaf->l)
            {
                insert(key, leaf->l);
            }
            else
            {
                leaf->l = new btnode;
                leaf->l->data = key;
                leaf->l->l = leaf->l->r = nullptr;
            }
        }
        else
        {
            if (leaf->r)
            {
                insert(key, leaf->r);
            }
            else
            {
                leaf->r = new btnode;
                leaf->r->data = key;
                leaf->r->l = leaf->r->r = nullptr;
            }
        }
    }
}

void binaryTree::printTree()
{
    printTree(root);
}

void binaryTree::printTree(btnode *leaf)
{
    if (!root)
    {
        return;
    }
    queue<btnode *> q;
    q.push(root);
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            btnode *leaf = q.front();
            cout << leaf->data << " ";
            q.pop();
            if (leaf->l)
            {
                q.push(leaf->l);
            }
            if (leaf->r)
            {
                q.push(leaf->r);
            }
            nodeCount--;
        }
        cout << endl;
    }
}

//basic depth first search algorithm
btnode *binaryTree::search(int key, btnode *leaf)
{
    if (leaf)
    {
        if (key == leaf->data)
        {
            return leaf;
        }
        if (key < leaf->data)
        {
            return search(key, leaf->l);
        }
        else
        {
            return search(key, leaf->r);
        }
    }
    else
    {
        return nullptr;
    }
}