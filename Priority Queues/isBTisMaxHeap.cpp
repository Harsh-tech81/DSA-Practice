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
int size(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
bool isCBT(Node *root)
{
    int s = size(root);
    queue<Node *> q;
    q.push(root);
    int count = 0;
    while (count < s)
    {
        Node *temp = q.front();
        q.pop();
        count++;
        if (temp)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    while (q.size())
    {
        if (q.front())
            return false;
        q.pop();
    }
    return true;
}
bool isMax(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left)
    {
        if (root->val <= root->left->val)
            return false;
    }
    if (root->right)
    {
        if (root->val <= root->right->val)
            return false;
    }
    return isMax(root->left) && isMax(root->right);
}
int main()
{
    Node *a = new Node(20); // root
    Node *b = new Node(15);
    Node *c = new Node(10);
    Node *d = new Node(8);
    Node *e = new Node(11);
    Node *f = new Node(6);
    Node *g = NULL;
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    //    Solution
    if (isCBT(a) && isMax(a))
        cout << "Given Binary Tree is MaxHeap" << endl;
    else
        cout << "Given Binary Tree is not a MaxHeap" << endl;

    return 0;
}