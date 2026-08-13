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

class Deque // User defined data structure
{
public:
    Node *head;
    Node *tail;
    int size;
    Deque() // constructor
    {
        head = tail = NULL;
        size = 0;
    }

    void pushBack(int val)
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

    void pushFront(int val)
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

    void popFront()
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

    void popBack()
    {
        if (size == 0)
        {
            cout << "List is Empty !!";
            return;
        }
        else if (size == 1)
        {
            popFront();
            return;
        }
        Node *temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Deque is Empty!" << endl;
            return -1;
        }
        return head->val;
    }

    int back()
    {
        if (size == 0)
        {
            cout << "Deque is Empty!" << endl;
            return -1;
        }
        return tail->val;
    }

    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
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
    Deque dq;
   
    // push pop back front size empty
   dq.pushBack(10);
   dq.pushBack(20);
   dq.pushBack(30);
   dq.pushBack(40);
    // cout<<q.size<<endl;
    //dq.display();
   dq.pushBack(50);
    //dq.pop()
   dq.pushBack(60);
   dq.pushBack(70);
    //  cout<<q.size<<endl;
   dq.pushBack(80);
   dq.pushBack(90);
   dq.pushBack(100);
    //dq.display();

   dq.display();
   dq.pushFront(0);
   dq.display();

    //dq.display();
    // cout <<  << endl; // opposite of the front it returns back of the Deque
    // cout <<dq.empty() << endl; // returns boolean value either true or false

    return 0;
}