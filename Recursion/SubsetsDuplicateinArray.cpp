#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void removechar2(vector<int> ans, vector<int> &nums, int idx, bool flag)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());   // sorting is very important 
    if (idx == n)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "  ";
        cout << endl;
        return;
    }

    int ch = nums[idx];
    if (nums.size() == 1)
    {
        if (flag == true)
            removechar2(ans, nums, idx + 1, true);
        ans.push_back(nums[idx]);
        removechar2(ans, nums, idx + 1, true);
        return; // taaki niche ki dono condition nahi chle esliye return kiya h
    }

    int dh = nums[idx + 1];
    if (ch == dh)
    { // duplicate exist then
        if (flag == true)
            removechar2(ans, nums, idx + 1, true);
        ans.push_back(nums[idx]);
        removechar2(ans, nums, idx + 1, false);
    }

    else
    { // when duplicate doesn't exist
        if (flag == true)
            removechar2(ans, nums, idx + 1, true);
        ans.push_back(nums[idx]);
        removechar2(ans, nums, idx + 1, true);
    }
}
int main()
{
    vector<int> nums = {4, 4, 4, 1, 4};
    vector<int> v;
    removechar2(v, nums, 0, true);
    //     [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
    // [[],[4],[1],[1,4],[4],[4,4],[4,1],[4,1,4],[4,4],[4,4,4],[4,4,1],[4,4,1,4],[4,4,4],[4,4,4,4],[4,4,4,1],[4,4,4,1,4]]
    return 0;
}