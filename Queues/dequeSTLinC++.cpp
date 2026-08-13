#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(0);

    // for(int i=0;i<n;i++) cout<<dq[i]<<"  ";
    dq.pop_back();
    dq.pop_front();
    cout << dq.size() << endl;

    for (int i = 0; i < dq.size(); i++)
        cout << dq[i] << "  ";

    return 0;
}