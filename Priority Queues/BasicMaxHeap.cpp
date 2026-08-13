#include <iostream>
#include <queue> // for accessing the priority queue
using namespace std;
int main()
{
    priority_queue<int> pq; // by default "maxHeap" is made automatically
    pq.push(10);
    pq.push(23);
    pq.push(3);
    cout << pq.top() << endl; // 10

    // pq.pop();                 // 10 is removed
    // cout << pq.top() << endl; // 3
    // pq.pop();
    // cout << pq.size() << endl; // 3

    // priority_queue<int, vector<int>, greater<int>> pq; // it is minHeap
    // pq.push(10);
    // pq.push(-5);
    // pq.push(3);
    // pq.push(-20);
    // cout << pq.top() << endl; //-20
    // pq.pop();                 // -20 is removed
    // cout << pq.top() << endl; // -5
    // pq.pop();                 //       -5 is removed
    // cout << pq.top() << endl; // 3


    return 0;
}