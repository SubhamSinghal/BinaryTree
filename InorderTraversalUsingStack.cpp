#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(node *root)
{
    stack<node *>st;
    node* curr = root;
    do
    {
        while(curr != NULL)
        {
             st.push(curr);
             curr = curr->left;
        }
        curr = st.top();
        cout << curr->data;
        if(st.empty())
            break;
        st.pop();
        curr = curr->right;
    }while(curr || !st.empty());
}
int main()
{
    struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
   inorderTraversal(root);
    return 0;
}
