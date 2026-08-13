#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    vector<int> nums = {3,-4,-7,30,7,-9,2,1,6,-1};
    int k = 3; // size of the window in Sliding Window
    int n = nums.size();
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
            q.push(i);
    }

    int i = 0;
    while (i <= n - k)
    { 
        while (q.size() && q.front() < i)
            q.pop();
        if (q.size() == 0 || q.front() >= i + k)
            ans.push_back(0);
        else
            ans.push_back(nums[q.front()]);
        i++;
    }


    for (int i = 0; i < n; i++)
        cout << nums[i] << "  ";
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";

    return 0;
}