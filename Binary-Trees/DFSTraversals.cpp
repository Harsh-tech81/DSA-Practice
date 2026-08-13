#include <iostream>
#include <cmath>
#include <climits>
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

void PreOrder(Node *root)
{
    if (root == NULL) // Base case
        return;
    cout << root->val << "  "; // root   --> Pre Order Traversal
    PreOrder(root->left);      // left
    PreOrder(root->right);     // right
}

void InOrder(Node *root)
{
    if (root == NULL) // Base case
        return;

    InOrder(root->left);       // left
    cout << root->val << "  "; // root   -->  In Order Traversal
    InOrder(root->right);      // right
}

void PostOrder(Node *root)
{
    if (root == NULL) // Base case
        return;

    PostOrder(root->left);     // left
    PostOrder(root->right);    // right
    cout << root->val << "  "; // root   -->  Post Order Traversal
}

int main()
{
    Node *a = new Node(1);
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
    // d->left = h;

    PreOrder(a);
    cout << endl;
    InOrder(a);
    cout << endl;
    PostOrder(a);
    cout << endl;


    
    return 0;
}