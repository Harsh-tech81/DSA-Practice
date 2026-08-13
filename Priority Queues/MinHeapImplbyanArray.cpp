#include <iostream>
// we are making our own heap by using OOPs Objects and Classes
using namespace std;
class MinHeap
{
public:
    int arr[50];
    int idx;
    MinHeap()
    { // constructor
        idx = 1;
    }
    int top()
    {
        return arr[1];
    }
    void push(int x)
    {
        arr[idx] = x;
        int i = idx;
        idx++;
        // Swapping of i with its parent if it satisfies the given condition till i==1
        while (i != 1)
        {
            if (arr[i / 2] > arr[i])
                swap(arr[i / 2], arr[i]);
            else
                break;
            i /= 2;
        }
    }
    int size()
    {
        return idx - 1;
    }
    void display()
    {
        for (int i = 1; i <= idx - 1; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
    void pop()
    {
        idx--;
        arr[1] = arr[idx];
        // Rearrangement
        int i = 1;
        while (1)
        {
            int l = 2 * i, r = 2 * i + 1;
            if (l > idx - 1)
                break;
            if (r > idx - 1)
            {
                if (arr[i] > arr[l])
                {
                    swap(arr[i], arr[l]);
                    i = l;
                }
                break;
            }
            if (arr[l] < arr[r])
            {
                if (arr[i] > arr[l])
                {
                    swap(arr[i], arr[l]);
                    i = l;
                }
                else
                    break;
            }
            else
            {
                if (arr[i] > arr[r])
                {
                    swap(arr[i], arr[r]);
                    i = r;
                }
                else
                    break;
            }
        }
    }
};
int main()
{
    MinHeap pq; // Initialization of the object and automatically constructor is invoked
    pq.push(10);
    pq.push(-45);
    pq.push(89);
    pq.push(2);
    pq.push(5);
    pq.display();
    pq.pop();

    // cout << pq.size() << endl;
    // cout << pq.top() << endl;
    pq.display();
    return 0;
}