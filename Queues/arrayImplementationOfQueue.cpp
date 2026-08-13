#include <iostream>
#include <vector>
using namespace std;
class Queue
{
public:
    int f;
    int b;
    int count;
    vector<int> arr;
    Queue(int val) // Constructor
    {
        f = 0;
        b = 0;
        count = 0;
        vector<int> v(val);
        arr = v;
    }
    void push(int val)
    {
        if (b == arr.size())
        {
            cout << "Queue is FULL !" << endl;
            return;
        }
        arr[b] = val;
        b++;
        count++;
    }
    void pop()
    {
        if (count == 0)
        {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        f++;
        count--;
    }
    int front()
    {
        if (count == 0)
        {
            cout << "Queue is EMPTY!" << endl;
            return -1;
        }
        return arr[f];
    }
    int back()
    {
        if (count == 0)
        {
            cout << "Queue is EMPTY!" << endl;
            return -1;
        }
        return arr[b - 1];
    }
    int size()
    {
        return count;
    }
    bool empty()
    {
        if (count == 0)
            return true;
        else
            return false;
    }
    void display()
    {
        for (int i = f; i < b; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q(8);
    // push pop back front size empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    // q.push(60);
    // q.push(70);
    // q.push(80);
    // q.display();
    // q.push(60);
    q.display();
    // q.pop();
    // q.display();
    cout << q.size() << endl; // opposite of the front it returns back of the queue
    // cout << q.empty() << endl; // returns boolean value either true or false
    return 0;
}