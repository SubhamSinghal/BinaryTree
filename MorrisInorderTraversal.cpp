#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left,*right;
};

node* newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void MorrisTraversal(node *root)
{
    node *curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout << curr->data << "\t";
            curr = curr->right;
        }
        else
        {
            node* pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if(pre->right == NULL)
             {
                 pre->right = curr;
                 curr = curr->left;
             }
             else
             {
                 pre->right = NULL;
                 cout << curr->data;
                 curr = curr->right;
             }
        }

    }
}
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    MorrisTraversal(root);

    return 0;
}
