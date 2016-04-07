#include <iostream>

using namespace std;

struct node
{
    char data;
    node *left,*right;
};

node* newNode(char data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int findPos(char inorder[], int low, int high, char data)
{
    for(int i = low; i <= high; ++i)
    {
        if(inorder[i] == data)
            return i;
    }
}
node* traverse(char pre[], char inorder[], int low, int high)
{
    if(low > high)
        return NULL;
    static int preIndex = 0;
    node* root = newNode(pre[preIndex++]);

    if(low == high)
        return root;

    int mid = findPos(inorder, low,high,root->data);
    root->left = traverse(pre,inorder, low, mid - 1);
    root->right = traverse(pre,inorder, mid + 1, high);

    return root;
}

void inorderTraversal(node* root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << "\t";
        inorderTraversal(root->right);
    }
}
int main()
{
    char inorder[] = {'D','B','E','A','F','C'};
    char pre[] = {'A','B','D','E','C','F'};
    node* root = traverse(pre,inorder,0,5);
    inorderTraversal(root);
    return 0;
}
