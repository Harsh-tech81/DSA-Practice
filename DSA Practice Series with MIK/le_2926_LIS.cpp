class Solution {
public:
    // try to memoize it by using unordered_map
    // bcz constraints are too large so we can't take 2-D DP with that size
    // Top-Down approach with memoization also gives TLE
    // unordered_map<string, long long> mp;
    // long long solve(int i, int prev, vector<int>& nums) {
    //     if (i >= nums.size()) {
    //         return 0; // if index out of bounds then sum is 0
    //     }
    //     string key = to_string(prev) + " " +
    //                  to_string(i); // create a key of string where two
    //                                // parameters are getting changed
    //     if (mp.count(key))
    //         return mp[key];
    //     long long take = INT_MIN;
    //     long long non_taken = INT_MIN;
    //     if (prev == -1 || nums[i] - i >= nums[prev] - prev) {
    //         take =
    //             nums[i] +
    //             solve(i + 1, i,
    //                   nums); // if taken then add the nums[i] to the total sum
    //     }
    //     non_taken = solve(i + 1, prev, nums);
    //     return mp[key] =
    //                max<long long>(take, non_taken); // typecast in long long
    // }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        // long long mx = LLONG_MIN;
        // for (int el : nums) {
        //     mx = max<long long>(mx, el);
        // }
        // if (mx <= 0)
        //     return mx;
        // // return solve(0, -1, nums);
        // // Now write its Bottom-Up solution which is also give TLE
        //    int n = nums.size();
        // vector<long long> t(n);  // t[i] denotes the LIS ending at the ith index
        // for(int i=0;i<n;i++){
        //     t[i]=(long long)nums[i];
        // }
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[i]-i>=nums[j]-j) {
        //             t[i] = max<long long>(nums[i] + t[j], t[i]);
        //             mx = max<long long>(mx, t[i]);
        //         }
        //     }
        // }
        // return mx;




    }
};