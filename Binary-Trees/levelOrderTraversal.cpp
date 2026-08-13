#include <iostream>
#include <cmath>
#include <climits>
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
int NoOfLevels(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(NoOfLevels(root->left), NoOfLevels(root->right));
}
void PrintNthLevel(Node *root, int Reqlevel, int currLevel) // we have to optimize the code
{
    if (root == NULL)
        return;
    if (Reqlevel == currLevel)
    {        
        cout << root->val << "  ";
        return;
    }
    PrintNthLevel(root->left, Reqlevel, currLevel + 1);
    PrintNthLevel(root->right, Reqlevel, currLevel + 1);
}

void levelOrder(Node *root)
{
    int n = NoOfLevels(root);
    for (int i = 1; i <= n; i++)
    {
        PrintNthLevel(root, i, 1);
        cout << endl;
    }
}
void PrintNthLevelReverse(Node *root, int Reqlevel, int currLevel) // we have to optimize the code
{
    if (root == NULL)
        return;
    if (Reqlevel == currLevel)
    {
        cout << root->val << "  ";
        return;
    }
    PrintNthLevelReverse(root->right, Reqlevel, currLevel + 1);
    PrintNthLevelReverse(root->left, Reqlevel, currLevel + 1);
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
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    // Node *h = new Node(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    // d->left = h;

    //   Level Order Traversals
    levelOrder(a);

    return 0;
}