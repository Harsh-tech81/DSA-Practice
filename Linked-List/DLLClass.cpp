#include <iostream>
using namespace std;
class Node // Doubly Linked List(DLL) Implementation
{
public:
    int val;
    Node *next;
    Node *prev; // extra for DLL
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL; // extra for DLL
    }
};

class DLL //  defined data structure
{
public:
    Node *head;
    Node *tail; // in this T.C. is O(1)  //in this we have used tail also now we have to do the same but without using tail
    int size;
    DLL() // constructor
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
            temp->prev = tail; // extra thing for DLL
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
            head->prev = temp; // Extra thing for DLL
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
            if (idx < size / 2) // Extra changed with optimized code
            {
                temp = head;
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->next;
                }
            }
            else
            {
                temp = tail;
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->prev;
                }
            }

            t->next = temp->next;
            temp->next = t;
            t->prev = temp;    // extra
            t->next->prev = t; // extra both line are important
            size++;
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
            if (idx < size / 2) // Extra changed with optimized code
            {
                for (int i = 1; i < idx; i++)
                {
                    temp = temp->next;
                } 
                temp->next = temp->next->next;
            temp->next->prev = temp; // extra
            }
            else
            {
                temp = tail;
                for (int i = 1; i < size-idx; i++)
                {
                    temp = temp->prev;
                }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
           
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
        if (head)
            head->prev = NULL; // extra thing for DLL
        if (head == NULL)
            tail = NULL;
        size--;
    }

    void deleteAtTail()
    {
        if (size == 0)
        {
            cout << "List is Empty !!";
            return;
        }
        else if (size == 1)
        {
            deleteAtHead();
            return;
        }
        Node *temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }
    // We can make better getIndex code with the help of the tail and prev node if idx is greater than half of the size we can search it in the next half of the LL
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
            if (idx < size / 2) // Extra changed with optimized code
            {
                temp = head;
                for (int i = 1; i <= idx; i++)
                {
                    temp = temp->next;
                }
            }
            else
            {
                temp = tail;
                for (int i = 1; i < idx; i++) // i<idx or i<size-idx  both are acceptable
                {
                    temp = temp->prev;
                }
            }

            return temp->val;
        }
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

    DLL ll;

    ll.insertAtTail(20);
    ll.display();
    cout << ll.size << endl;
    ll.insertAtTail(30);
    ll.display();
    cout << ll.size << endl;
    ll.insertAtHead(1);
    ll.display();
    cout << ll.size << endl;
    ll.insertAtGivenIndex(25, 2);
    ll.display();
    cout << ll.size << endl;
    ll.insertAtGivenIndex(10, 1);
    ll.display();
    cout << ll.size << endl;
    //  ll.deleteAtHead();
    //     ll.display();
    //     cout << ll.size << endl;
    //  ll.deleteAtTail();
    //     ll.display();
    //     cout << ll.size << endl;

    ll.deleteAtIndex(3);
    ll.display();
    cout << ll.size << endl;

    // cout << ll.getAtIdx(2) << endl;
    // cout << ll.getAtIdx(0) << endl;
    // cout << ll.getAtIdx(1) << endl;
    // cout << ll.getAtIdx(2) << endl;
    // cout << ll.getAtIdx(3) << endl;

    return 0;
}