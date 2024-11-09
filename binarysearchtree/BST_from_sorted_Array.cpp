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

Node* buildbstfromsortedarr(int arr[],int start,int end)
{

  if(start>end)
  {
    return NULL;
  }
   int  mid=  (start+end)/2;

   Node* root =new Node(arr[mid]);

   root->left= buildbstfromsortedarr(arr,start,mid-1);
   root->right= buildbstfromsortedarr(arr,mid+1,end);
   return root;
}
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
int main()
{
   /* int n=0;
    int *arr=new int(n);
    cout<<"enter the no of element in array:"<<endl;
    cin>>n;
    cout<<"enter the element in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }*/

    int arr[]={10,20,30,40,50};
Node* root=buildbstfromsortedarr(arr,0,4);
printpreorder(root);
return 0;

}