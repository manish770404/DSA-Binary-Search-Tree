#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data =val;
        left=NULL;
        right=NULL;
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
void printinorder(struct Node* root)
{
    if(root==NULL)
    {
        return ;
    }
     printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);

}
Node* searchinbst(Node* root,int key)
{

    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    if(root->data>key)
    {
        return searchinbst(root->left,key);
    }
    return searchinbst(root->right,key);
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
    //printinorder( root);

    if(searchinbst(root,87)==NULL)
    {
        cout<<"key doesn`t exist"<<endl;
    }
    else{
        cout<<"key exist"<<endl;
    }
  return 0;
}