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
//calls the private member recursive function with access to root
void binaryTree::deleteTree()
{
    deleteTree(root);
    root = nullptr;
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
//calls private member recursive function with access to the root node
void binaryTree::insert(int key)
{
    insert(key, root);
}

//recursive private member function that inserts nodes in the tree
void binaryTree::insert(int key, btnode *leaf)
{
    //creation of root node
    if (!root)
    {
        root = new btnode;
        root->data = key;
        root->l = root->r = nullptr;
    }
    //creation of every other node
    else
    {
        //check for left sided data
        if (key < leaf->data)
        {
            //check for left node. If it exists run the function recursively
            if (leaf->l)
            {
                insert(key, leaf->l);
            }
            //if the left node doesn't exist create a new one
            else
            {
                leaf->l = new btnode;
                leaf->l->data = key;
                leaf->l->l = leaf->l->r = nullptr;
            }
        }
        //check for right sided data
        else
        {
            //check for right node. If it exists run the function recursively
            if (leaf->r)
            {
                insert(key, leaf->r);
            }
            //if the right node doesn't exist create a new one
            else
            {
                leaf->r = new btnode;
                leaf->r->data = key;
                leaf->r->l = leaf->r->r = nullptr;
            }
        }
    }
}

//public member function that allows for the tree to be printed
//calls the private member function with access to the root node
void binaryTree::printTree()
{
    printTree(root);
}

//private member function that prints the tree with depth.
//uses a queue to recognize nodes and print them
void binaryTree::printTree(btnode *leaf)
{
    if (!root)
    {
        return;
    }
    queue<btnode *> q;
    q.push(root);
    //run until all nodes have been printed
    while (!q.empty())
    {
        int nodeCount = q.size();
        //run until all nodes are popped out of the queue
        while (nodeCount > 0)
        {
            btnode *leaf = q.front();
            cout << leaf->data << " ";
            q.pop();
            //add to the queue if a left node exists
            if (leaf->l)
            {
                q.push(leaf->l);
            }
            //add to the queue if a right node exists
            if (leaf->r)
            {
                q.push(leaf->r);
            }
            //remove count on the node popped
            nodeCount--;
        }
        cout << endl;
    }
}

//basic (recursive) search algorithm
btnode *binaryTree::search(int key, btnode *leaf)
{
    //if the node exists
    if (leaf)
    {
        //if the key is equal to the data return the node
        if (key == leaf->data)
        {
            return leaf;
        }
        //if the key is less than the data check the left node
        if (key < leaf->data)
        {
            return search(key, leaf->l);
        }
        //if the key is more or equal to the data check the right node
        else
        {
            return search(key, leaf->r);
        }
    }
    //if the node doesn't exist return nullptr.
    else
    {
        return nullptr;
    }
}