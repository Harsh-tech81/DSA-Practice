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
    Node *tail; // in this T.C. is O(1)  //in this we have used tail also now we have to do the same but without using tail 
    int size;
    LinkedList() // constructor
    {
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = tail = temp;
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
            return tail->val;
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
    // Delete from a particular index

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
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
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

    // cout << ll.getAtIdx(40) << endl;
    ll.deleteAtIndex(5);
    // ll.deleteAtHead();
    // ll.deleteAtTail();
    ll.display();
    cout << ll.size << endl;

    return 0;
}