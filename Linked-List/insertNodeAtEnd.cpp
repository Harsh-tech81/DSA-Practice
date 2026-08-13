#include <iostream>
using namespace std;
class Node // Linked list Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtEnd(Node *Head, int val)
{
    Node *temp = Head;
    Node *i = new Node(val);
    while (temp->next != NULL) // in this T.C. is O(n)
    {
        temp = temp->next;
    }
    temp->next = i;
    cout << endl;
}
void insertAtStart(Node *Head, int val)
{ Node *temp = Head;
    Node *T = new Node(val);
    T->next = temp;
    temp = T;
    cout << endl;
}
int count(Node *Head)
{
    int count = 0;
    Node *temp = Head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << endl;
    return count;
}

int main()
{
    // 10 20 30 40 50  // by using pointers only we can do it
    Node *a = new Node(10); //  it is DMA by using the new keyword Dynamic memory Allocation
    Node *b = new Node(20); // we will always use pointers in the linked list in this way always
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(a);
    cout << count(a);
    insertAtEnd(a, 70);
    display(a);
    cout << count(a);
    insertAtStart(a, 3);
    display(a);
    cout << count(a);

    return 0;
}