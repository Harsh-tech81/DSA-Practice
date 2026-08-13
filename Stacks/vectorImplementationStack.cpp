#include <iostream>
#include <vector>
using namespace std;

class Stack
{ // user defined data structure
public:
    vector<int> vec; // unlimited size of the stack
                     // No Overflow condition
    Stack()
    { // constructor
    }

    void push(int val)
    {
        vec.push_back(val);
        cout << endl;
    }
    void pop() // But Underflow condition exists
    {
        if (vec.size() == 0)
        {
            cout << "Stack is Empty !" << endl;
            return;
        }
        vec.pop_back();
        cout << endl;
    }
    int top()
    {
        if (vec.size() == 0)
        {
            cout << "Stack is Empty !" << endl;
            return -1;
        }
        cout << endl;
        return vec[vec.size() - 1];
    }
    int size()
    {
        cout << endl;
        return vec.size();
    }
};

int main()
{
    Stack st;
    st.top(); // Underflow error is that Stack is empty
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout << st.size();
    cout << st.top();
    st.pop();
    cout << st.size();
    cout << st.top();

    return 0;
}