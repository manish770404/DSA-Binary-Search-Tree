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
Node* insertbst(Node* root,int val)
{
    if(root==NULL)
    {
        Node* node=new Node(val);
        return node;
    }
    if(val<root->data)
    {
        root->left=insertbst(root->left,val);
    }
    else{
        root->right=insertbst(root->right,val);
    }

    return root;
}

bool isbst(Node* root, Node* min = NULL, Node* max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftvalid = isbst(root->left, min, root);
    bool rightvalid = isbst(root->right, root, max);

    return leftvalid && rightvalid;
}
int main()
{
    Node* root=NULL;
    root=insertbst(root,5);
    insertbst(root,1);
    insertbst(root,3);
    insertbst(root,4);
    insertbst(root,2);
    insertbst(root,7);

    if(isbst(root,NULL,NULL))
    {
        cout<<"valid bst";
    }
    else{
        cout<<"invalid bst";
    }


    return 0;
}