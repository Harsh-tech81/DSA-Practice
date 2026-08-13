
#include <iostream>
using namespace std;
class Node
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
class LinkedList // User defined data structure
{
public:
    Node *head;
    int size;
    LinkedList() // constructor
    {
        head = NULL;
        size = 0;
    }

    Node *deleteNode(Node *head, Node *target)
    {
        if (head == target)
        {
            head = head->next;
            return head;
        }
        Node *temp = head;
        while (temp->next != target)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
        return head;
    }

    Node *deletebyValue(Node *head, int target)
    {
        if (head->val == target)
        {
            head = head->next;
            return head;
        }
        Node *temp = head;
        while (temp->next->val != target)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
        return head;
    }
    void Delete(Node *node)
    {

        node->val = node->next->val;
        node->next = node->next->next;

        // size--;
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

    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Node *head = a;
    LinkedList ll; // make a linked list class and a variable ll linkedList

    display(head);
    cout << count(head);
    // head = ll.deleteNode(head, c);
    // head = ll.deletebyValue(head, a->val);
    ll.Delete(c);
    cout << endl;
    display(head);
    cout << count(head);

    return 0;
}