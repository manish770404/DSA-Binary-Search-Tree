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
void zigzagLevelOrder(Node* root) {
    if (root == nullptr)
        return;
    
    queue<Node*> q;
    stack<int> s;
    bool flag = true; // Flag to toggle the direction of traversal
    
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            
            if (flag)
                cout << node->data << " ";
            else
                s.push(node->data);
            
            if (node->left)
                q.push(node->left);
            
            if (node->right)
                q.push(node->right);
        }
        
        // Print nodes in reverse order if flag is false
        if (!flag) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
        
        flag = !flag; // Toggle the flag
        cout << endl;
    }
}

int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    zigzagLevelOrder(root);
}
