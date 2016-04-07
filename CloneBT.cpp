#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left,*right,*random;
};

node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = temp->random = NULL;
    return temp;
}

void cloneBT(node* root)
{
    if(root != NULL)
    {
        node* clone = newNode(root->data);
        clone->left = root->left;
        root->left = clone;
        cloneBT(root->left->left);
        cloneBT(root->right);
        if(root->right)
            clone->right = root->right->left;
    }
}
void cloneRandom(node* root)
{
    if(root != NULL)
   {
        node* clone = root->left;
        if(root->random)
            clone->random = root->random->left;
        cloneRandom(root->left->left);
        cloneRandom(root->right);
   }
}

void restoreBT(node* root, node* clone)
{
    if(root != NULL && clone != NULL)
    {
        if(clone->left != NULL)
        {
            root->left = root->left->left;
            clone->left = clone->left->left;
        }
        else
            root->left = NULL;
        //if(root->left && clone->left)
        restoreBT(root->left,clone->left);
        restoreBT(root->right,clone->right);
    }
}
void printInorder(node* root)
{
    if(root != NULL)
    {
        cout << "[" << root->data << " ";
        if(root->random)
            cout << root->random->data << "]";
        else
            cout << "NULL]";
        printInorder(root->left);
        printInorder(root->right);
    }
}
int main()
{
    node *tree = newNode(1);
    tree->left = newNode(2);
    tree->right = newNode(3);
    tree->left->left = newNode(4);
    tree->left->right = newNode(5);
    tree->right->left = newNode(6);
    tree->right->right = newNode(7);
    tree->random = tree->left;
    cloneBT(tree);
    cloneRandom(tree);
    node *clone = tree->left;
    restoreBT(tree,clone);
    printInorder(clone);
    return 0;
}
