class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k, vector<int>& nums, vector<int> v, int prev) {
        if (v.size() >= 2)
            ans.push_back(v);
        if (k >= nums.size())
            return;
        set<int> st;
        for (int i = k; i < nums.size(); i++) { // try all the indices one by one
            if (st.count(nums[i]))
                continue;
            if (prev == -1 || nums[i] >= nums[prev]) {
                v.push_back(nums[i]);
                st.insert(nums[i]);
                solve(i + 1, nums, v, i);
                v.pop_back();  // backtrack the changes 
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        solve(0, nums, v, -1);
        return ans;
    }
};