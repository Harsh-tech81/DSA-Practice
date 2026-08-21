class Solution {
public:
    int dp[100002];
    bool solve(int i, vector<int>& nums) {
        int n = nums.size();
        if (i >= n)
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool step1 = false, step2 = false, step3 = false;
        if (i + 1 < n && nums[i] == nums[i + 1]) {
            step1 = solve(i + 2, nums);
        }
        if (i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
            step2 = solve(i + 3, nums);
        if (i + 2 < n && (nums[i + 1] - nums[i] == 1) &&
            (nums[i + 2] - nums[i + 1] == 1))
            step2 = solve(i + 3, nums);
        return dp[i] = step1 || step2 || step3;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};