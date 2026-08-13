#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Node
{ // This  is a TreeNode
public:
    int val;
    Node *left;
    Node *right;
    Node(int val) // Constructor to initialize the values
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void displayTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << "  ";
    displayTree(root->left);
    displayTree(root->right);
    // displayTree(root->left);
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;
    return root->val + sum(root->left) + sum(root->right);
}
int Product(Node *root)
{
    if (root == NULL)
        return 1;
    return root->val * Product(root->left) * Product(root->right);
}
int size(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int NoOfLevels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1+ max(NoOfLevels(root->left),NoOfLevels(root->right));
}

int maxInTree(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int lmax = maxInTree(root->left);
    int rmax = maxInTree(root->right);
    return max(root->val, max(lmax, rmax));
}

int minInTree(Node *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    int lmax = minInTree(root->left);
    int rmax = minInTree(root->right);
    return min(root->val, min(lmax, rmax));
}
int main()
{
    Node *a = new Node(1); // Root Node
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    Node *h = new Node(8);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->left = h;

    displayTree(a); 
    cout << endl;

    // cout << sum(a) << endl;
    // cout << size(a) << endl;
     cout << NoOfLevels(a) << endl;
    // cout << maxInTree(a) << endl;
    // cout << minInTree(a) << endl;
    // cout << Product(a) << endl;

    return 0;
}