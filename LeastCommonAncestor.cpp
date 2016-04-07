#include <iostream>

using namespace std;

struct node
{
    node *left, *right;
    int key;
};

node* newNode(int key)
{
    node *temp = new node();
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

node* findLca(node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->key == n1 || root->key == n2)
        return root;

    node* left_lca = findLca(root->left, n1, n2);
    node* right_lca = findLca(root->right, n1, n2);

    if(left_lca && right_lca)
        return root;
    return (left_lca != NULL)?left_lca :right_lca;
}
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA of (4,5) = " << findLca(root, 4,5)->key;
    cout << "\nLCA of (3, 6) = " << findLca(root, 3, 6)->key;

    return 0;
}
