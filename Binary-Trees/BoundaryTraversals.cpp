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

// Making the function for the boundary printing like left boundary,leaf Nodes and right boundary
void leftBoundary(Node *root)
{
    if (root == NULL)
        return; // base case of the recursion
    if (root->left == NULL && root->right == NULL)
        return;                // condition for the leaf Node
    cout << root->val << "  "; //  preOrderTraversal
    leftBoundary(root->left);
    if (root->left == NULL)
        leftBoundary(root->right);
}

void bottomBoundary(Node *root)   // Printing of the leaf Nodes 
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->val << "  "; // preOrderTraversal
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}

void RightBoundary(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    RightBoundary(root->right); // postOrderTraversal
    if (root->right == NULL)
        RightBoundary(root->left);
    cout << root->val << "  ";
}
void Boundary(Node *root)
{
    leftBoundary(root);
    bottomBoundary(root);
    RightBoundary(root->right);
}

int main()
{
    // Construct Tree using function
    int arr[] = {
        1,
        2,
        3,
        4,
        5,
        INT_MIN,
        6,
        7,
        INT_MIN,
        8,
        INT_MIN,
        9,
        10,
        INT_MIN,
        11,
        INT_MIN,
        12,
        INT_MIN,
        13,
        INT_MIN,
        14,
        15,
        16,
        INT_MIN,
        17,
        INT_MIN,
        INT_MIN,
        18,
        INT_MIN,
        19,
        INT_MIN,
        INT_MIN,
        INT_MIN,
        20,
        21,
        22,
        23,
        INT_MIN,
        24,
        25,
        26,
        27,
        INT_MIN,
        INT_MIN,
        28,
        INT_MIN,
        INT_MIN,
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = construct(arr, n);
    // levelOrder(root);   // check the tree which is made is right or not by printing via level order in each line

    // Boundary Traversal
    Boundary(root);

    return 0;
}