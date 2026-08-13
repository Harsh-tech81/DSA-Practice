#include <bits/stdc++.h>
using namespace std;

    void f(vector<int>& nums, vector<int>& temp) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int idx = 0; idx < nums.size(); idx++) {
            int el = nums[idx];
            vector<int>ans1;
            for(int i=0;i<idx;i++) ans1.push_back(nums[i]);
            for(int i=idx+1;i<nums.size();i++) ans1.push_back(nums[i]);
            temp.push_back(el);
            f(ans1, temp);
            temp.pop_back();
        }
    }

int main() {
  vector<int> orig = {1};

  vector<int> ans;

  permutations(ans, orig);
}