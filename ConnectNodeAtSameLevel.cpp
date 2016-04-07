#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left,*right,*nextright;
};

node* newnode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = temp->nextright = NULL;
    return temp;
}

void connectAtSameLevel(node* root)
{
    if(root != NULL)
    {
        if(root->left)
        {
            root->left->nextright = root->right;
        }
        if(root->right && root->nextright)
        {
            root->right->nextright = root->nextright->left;
        }

        connectAtSameLevel(root->left);
        connectAtSameLevel(root->right);
        //return root;
    }

}

void inorder(node* root)
{
    if(root != NULL)
    {
        cout << root->data << "\t";
        if(root->nextright)
            cout << root->nextright->data <<"\n";
        else
            cout << "\n";
        inorder(root->left);
        inorder(root->right);
    }
}
int main()
{
    node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    connectAtSameLevel(root);

    inorder(root);

    return 0;
}
