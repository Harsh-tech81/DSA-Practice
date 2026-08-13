#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Node 
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

class LinkedList 
{
public:
    Node *head;
    int size;
    LinkedList() 
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
    int count(Node *Head)
    {
        int count = 0;
        Node *temp = Head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout << endl;
        return count;
    }
};
void printStack(stack<int> st)
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

    // while (st.size())
    // {
    //     temp.push(st.top());
    //     st.pop();
    // }
    // while (temp.size())
    // {
    //     temp2.push(temp.top());
    //     temp.pop();
    // }
    // while (temp2.size())
    // {
    //     st.push(temp2.top());
    //     temp2.pop();
    // }

    // printStack(st);

    // By using Arrays By storing the values in the array it can be do easily
    //     int n = st.size();
    // int arr[n];
    //     int i=0;
    //      while (st.size() && i<n)
    //         {
    //           arr[i]=st.top();
    //             st.pop();
    //             i++;
    //         }

    //     for(int i=0;i<n;i++){
    //        st.push(arr[i]);
    //     }

    // printStack(st);

    // Now reverse the elements of the stack using vector
    // vector<int> vec;

    // while (st.size())
    // {
    //     vec.push_back(st.top());
    //     st.pop();
    // }
    // int n = vec.size();
    // for (int i = 0; i < n; i++)
    // {
    //     st.push(vec[i]);
    // }

    // printStack(st);

    // Now reverse the stack using LinkedList
    LinkedList ll;
    while (st.size())
    {
        ll.insertAtTail(st.top());
        st.pop();
    }
    int n = ll.size;
    for (int i = 0; i < n; i++)
    {
        st.push(ll.getAtIdx(i));
    }

    printStack(st);

    return 0;
}