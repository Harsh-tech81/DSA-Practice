// Without using tail we can implement it
#include <iostream>
using namespace std;
class Node // User defined data type
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

    void insertAtTail(int val)
    {
        Node *t = new Node(val);
        if (size == 0)
        {
            head = t;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < size; i++)
            {
                temp = temp->next;
            }
            temp->next = t;
        }
        size++;
    }

    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtGivenIndex(int val, int idx)
    {
        if (idx < 0 || idx > size)
            cout << "Invalid Index" << endl;
        else if (idx == 0)
            insertAtHead(val);
        else if (idx == size)
            insertAtTail(val);
        else
        {
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int getAtIdx(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid Index";
            return -1;
        }

        else if (idx == 0)
            return head->val;
        else if (idx == size - 1)
        {
            Node *temp = head;
            for (int i = 1; i < size; i++)
            {
                temp = temp->next;
            }

            return temp->val;
        }

        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx; i++)
            {
                temp = temp->next;
            }
            return temp->val;
        }
    }
    // // Delete from a particular index

    void deleteAtIndex(int idx)
    {
        if (size == 0)
        {
            cout << "List is Empty !!";
            return;
        }
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        else if (idx == 0)
            return deleteAtHead();
        else if (idx == size - 1)
            return deleteAtTail();
        else
        {
            Node *temp = head;
            for (int i = 1; i < idx; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }
    void deleteAtHead()
    {
        if (size == 0)
        {
            cout << "List is Empty !!";
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtTail()
    {
        if (size == 0)
        {
            cout << "List is Empty !!";
            return;
        }
        Node *temp = head;
        for (int i = 1; i < size - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        size--;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll; // {  }
    ll.insertAtTail(10);
    ll.display(); // {10->NULL}
    cout << ll.size << endl;
    ll.insertAtTail(20); // {10->20->NULL}
    ll.display();
    cout << ll.size << endl;

    ll.insertAtTail(40);
    ll.insertAtTail(50);
    ll.display();
    cout << ll.size << endl;

    ll.insertAtHead(5);
    ll.display();
    cout << ll.size << endl;
    ll.insertAtHead(1);
    ll.display();
    cout << ll.size << endl;

    ll.insertAtGivenIndex(100, 3);
    ll.display();
    cout << ll.size << endl;

    ll.insertAtGivenIndex(70, 5);
    ll.display();
    cout << ll.size << endl;

    // Get value of the linked list on the basis of the known index value

    cout << ll.getAtIdx(4) << endl;
    ll.deleteAtIndex(5);
    ll.display();
    cout << ll.size << endl;
    ll.deleteAtHead();
    ll.display();
    cout << ll.size << endl;
    ll.deleteAtTail();
    ll.display();
    cout << ll.size << endl;

    return 0;
}