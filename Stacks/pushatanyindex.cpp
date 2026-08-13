#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void pushAtBottom(int val, stack<int> &st)
{
    vector<int> vec;
    while (st.size())
    {
        vec.push_back(st.top());
        st.pop();
    }
    int n = vec.size();
    st.push(val);
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(vec[i]);
    }
    cout << endl;
}
void pushAtBottomRecursively(int val, stack<int> &st){
     if (st.size() == 0){
           st.push(val);
               return;
     }
     
    int x = st.top();
    st.pop();
    pushAtBottomRecursively(val,st);
    st.push(x);
    
}
void pushAtAnyIndex(int val, stack<int> &st, int idx)  // address operator is neccessary 
{
    vector<int> vec;
    while (st.size() - idx)
    {
        vec.push_back(st.top());
        st.pop();
    }
    int n = vec.size();
    st.push(val);
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(vec[i]);
    }
    cout << endl;
}

void printStack(stack<int> &st)
{
    stack<int> temp;
    while (st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    while (temp.size())
    {
        cout << temp.top() << "  ";
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    stack<int> temp;
    stack<int> temp2;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    printStack(st);
    cout << st.size() << endl;
    // pushAtBottomRecursively(5, st);
    // // cout<<endl;
    // // printStack(st);
    // cout << st.size() << endl;
    // pushAtBottomRecursively(60, st);
    // cout << st.size() << endl;
    // printStack(st);

    // // Now make a function to push at any given index
    // pushAtAnyIndex(25, st, 5);
    // printStack(st);
    // cout << st.size() << endl;

pushAtBottomRecursively(5,st);
 printStack(st);
 cout << st.size() << endl;
pushAtBottomRecursively(10,st);
 printStack(st);
  cout << st.size() << endl;

    return 0;
}