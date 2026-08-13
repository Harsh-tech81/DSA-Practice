#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void revinorder(Node *root, vector<int> &dec)
{
    if (root == NULL)
        return;
    revinorder(root->right, dec);
    dec.push_back(root->val); // reverse order traversal of BST gives a decreasing sorted array
    revinorder(root->left, dec);
}
void preorder(Node *root, vector<int> &dec, int &idx)
{
    if (root == NULL)
        return;
    root->val = dec[idx++];
    preorder(root->left, dec, idx);
    preorder(root->right, dec, idx);
}
void levelOrderQueue(Node *root) // This Technique of printing using Queue is known as BFS (Breadth First Search)
{
    queue<Node *> q;
    q.push(root);
    while (q.size())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << "  ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    cout << endl;
}
int main()
{

    Node *a = new Node(10);
    Node *b = new Node(5);
    Node *c = new Node(16);
    Node *d = new Node(1);
    Node *e = new Node(8);
    Node *f = new Node(12);
    Node *g = new Node(20);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    vector<int> dec; // reverse inorder
    revinorder(a, dec);
    // for (int ele : dec)
    //     cout << ele << "  ";
    // cout << endl;
    levelOrderQueue(a);
    int i = 0;
    preorder(a, dec, i); // BST--> MaxHeap
    levelOrderQueue(a);

    
    return 0;
}