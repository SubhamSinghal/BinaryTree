#include <iostream>

using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
};

struct node* binaryUntil(struct node* root)
{
        if(root == NULL)
            return root;

        if(root->left != NULL)
        {
            node* n = binaryUntil(root->left);

            for(; n->right != NULL; n = n->right);

            n->right = root;
            root->left = n;
        }

        if(root->right != NULL)
        {
            node *r = binaryUntil(root->right);

            for(; r->left != NULL; r = r->left);

            r->left = root;
            root->right = r;
        }
        return root;
}


struct node* newNode(int key)
{
        node * root = new node;
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        return root;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
