#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printpreorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpreorder(root->left);
    printpreorder(root->right);
}

Node *construct(int preorder[], int *index, int key, int min, int max, int n)
{
    if (*index >= n)
    {
        return NULL;
    }

    Node *root = NULL;

    if (key > min && key < max)
    {
        root = new Node(key);
        *index = *index + 1;

        if (*index < n)
        {
            root->left = construct(preorder, index, preorder[*index], min, key, n);
        }
        if (*index < n)
        {
            root->right = construct(preorder, index, preorder[*index], key, max, n);
        }
    }

    return root;
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int index = 0;
    Node *root = construct(preorder, &index, preorder[0], INT_MIN, INT_MAX, n);
    cout << "Preorder traversal: ";
    printpreorder(root);
    return 0;
}
