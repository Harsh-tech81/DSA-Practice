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

class Queue // User defined data structure
{
public:
    Node *head;
    Node *tail;
    int size;
    Queue() // constructor
    {
        head = tail = NULL;
        size = 0;
    }

    void push(int val)
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
    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp=head;
        head = head->next;
        size--;
        delete(temp); // wastage of the Node nhi ho rhi h esse upon deletion of the Node 
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return head->val;
    }
    int back()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
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
    Queue q;
    // q.pop();  
    // push pop back front size empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    // cout<<q.size<<endl;
    // q.display();
    q.push(50);
    // q.pop()
    q.push(60);
    q.push(70);
    //  cout<<q.size<<endl;
    q.push(80);
    q.push(90);
    q.push(100);
    // q.display();
    // q.push(60);
    q.display();
    // q.pop();
    // q.display();
    cout << q.size << endl; // opposite of the front it returns back of the queue
    // cout << q.empty() << endl; // returns boolean value either true or false

    return 0;
}