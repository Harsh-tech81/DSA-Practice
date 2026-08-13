#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <unordered_map>
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
Node *construct(int arr[], int n)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while (q.size() && i < n)
    {
        Node *temp = q.front();
        q.pop();
        Node *l;
        Node *r;
        if (arr[i] != INT_MIN)
            l = new Node(arr[i]);
        else
            l = NULL;
        if (j != n && arr[j] != INT_MIN)
            r = new Node(arr[j]);
        else
            r = NULL;
        temp->left = l;
        temp->right = r;
        if (l != NULL)
            q.push(l);
        if (r != NULL)
            q.push(r);
        i += 2;
        j += 2;
    }
    return root;
}
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
void TopView(Node *root)
{
    queue<pair<Node *, int>> q; // queue of pair contains Node* and int value    <Node,level>
    unordered_map<int, int> m;   // <level,root->val>
    pair<Node *, int> p1;
    p1.first = root;
    p1.second = 0;
    q.push(p1);
    // Apply BFS using a queue
    while (q.size())
    {
        Node *temp = (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if (m.find(level) == m.end()) // if level is not exist in map then insert in the map
            m[level] = temp->val;
        if (temp->left)
        {
            pair<Node *, int> p1;
            p1.first = temp->left;
            p1.second = level - 1;
            q.push(p1);
        }
        if (temp->right)
        {
            pair<Node *, int> p1;
            p1.first = temp->right;
            p1.second = level + 1;
            q.push(p1);
        }
    }
    int minLev = INT_MAX;
    int maxL = INT_MIN;
    for (auto x : m)
    {
        minLev = min(x.first, minLev);
        maxL = max(x.first, maxL);
    }
    for (int i = minLev; i <= maxL; i++)
    {
        cout << m[i] << "  ";
    }
    cout << endl;
}
int main()
{
    // Construct Tree using function
    int arr[] = {1, 2, 3, 4, 5, INT_MIN, 6, INT_MIN, INT_MIN, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct(arr, n);

    //   Level Order Traversals
    levelOrder(root);

    // Printing top view of the BT
    cout << endl;

    TopView(root);

    return 0;
}