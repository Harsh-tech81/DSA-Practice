#include <iostream>
#include <stack>
using namespace std;
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
    st.pop();
     st.pop();
      st.pop();
       st.pop();
        st.pop();
    // int n = st.size();
    // int arr[n];

    // cout << st.empty() << endl;

    // Printing in the reverse order (we are emptying the stack which is drawback )
    // for(int i=1;i<=n;i++){
    //     cout<<st.top()<<"  ";
    //     st.pop();
    // }
    // we've used extra stack for printing

    // while (st.size())
    // {
    //     cout << st.top() << "  ";
    //     temp.push(st.top());
    //     st.pop();
    // }
    // cout << endl;

    // cout << st.size() << endl;
    // cout << temp.size() << endl;

    // Putting elements back to st feom the temp
    // while (temp.size())
    // {
    //     cout << temp.top() << "  ";
    //     st.push(temp.top());
    //     temp.pop();
    // }
    // cout << endl;

    // cout << st.size() << endl;
    // cout << temp.size() << endl;

    // I want to print the index value

    //   while (temp.size())
    //     {
    //         temp2.push(temp.top());
    //         temp.pop();
    //     }
    //     cout << endl;

    //  while (temp2.size())
    //     {
    //         st.push(temp2.top());
    //         temp2.pop();
    //     }
    //     cout << endl;

    //      while (st.size())
    //     {
    //         cout << st.top() << "  ";
    //         temp.push(st.top());
    //         st.pop();
    //     }
    //     cout << endl;

    // cout<<st.size()<<endl;
    // cout<<temp.size()<<endl;
    // cout<<temp2.size()<<endl;

    // By storing the values in the array it can be do easily
    // int i = 0;
    // while (st.size() && i < n)
    // {
    //     cout << st.top() << "  ";
    //     arr[i] = st.top();
    //     st.pop();
    //     i++;
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     st.push(arr[i]);
    // }

    // cout << endl;

    // // cout<<st.size();

    // i = 0;
    // while (st.size() && i < n)
    // {
    //     cout << st.top() << "  ";
    //     arr[i] = st.top();
    //     st.pop();
    //     i++;
    // }
    // cout << endl;
cout<<st.top();  // it gives the stack underflow error because stack is empty 


    return 0;
}