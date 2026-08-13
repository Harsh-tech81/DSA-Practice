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
    return count;
}

// now print by recursion
void recursive(Node *temp)
{
    if (temp == NULL)
        return;
    //  cout<<temp->val<<"  ";
    recursive(temp->next); // call phle kaam baad me wala concept used hua h
    cout << temp->val << "  ";
}

int main()
{
    // 10 20 30 40 50  // by using pointers only we can do it 
    Node *a = new Node(10);  //  it is DMA by using the new keyword Dynamic memory Allocation 
    Node *b = new Node(20);  // we will always use pointers in the linked list in this way always 
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    // display(a);
    // cout<<endl;
    // cout << count(a);

    // cout<<a->val<<endl<<a->next->val<<endl<<a->next->next->val<<endl<<a->next->next->next->val<<endl<<a->next->next->next->next->val;

    // now print by recursion
    recursive(a);


    
    return 0;
}