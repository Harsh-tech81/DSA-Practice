#include <iostream> // we don't use stack headerFile
using namespace std;
class Stack
{ // user defined data structure which is a Stack using Array

public:
    int arr[5]; // limited size of the stack
    int idx,size;
    int n = sizeof(arr) / sizeof(int); // in this way calculate the size of the array
    Stack()
    { // constructor
        idx = -1;
    size=0;
    }

    void push(int val)
    {
        if (idx == n - 1)
        {
            cout << "Stack is Full" << endl;
            return;
        }
        idx++;
        arr[idx] = val;
        size++;
        cout << endl;
    }
    void pop()
    {
        if (idx == -1)
        {
            cout << "Stack is empty";
            return;
        }
        idx--;
        cout << endl;
        size--;
    }
    int top()
    {
        if (idx == -1)
        {
            cout << "Stack is empty";
            return -1;
        }
        cout << endl;
        return arr[idx];
    }
    int size1()
    {
        cout << endl;
        return size;
    }
    void display()
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st; // object bnaye h class ka
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40); // it is limited stack is of the size 5 maximum
    st.push(50);
    // st.push(60);
    // cout << st.size() << endl;
    // cout<<st.top();  // 50 is at the top 60 is not inserted
    st.display();

    // st.pop();
    // cout<<st.size();
    // cout<<st.top();
    // cout<<st.size();

    return 0;
}