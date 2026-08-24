class Solution {
public:
        int binary_search_to_find_lower_bound(vector<int>&sorting,int target){
            int i=0;
            int j=sorting.size()-1;
            int storeIdx=-1;
            while(i<=j){
                int mid=i+(j-i)/2;
                if(sorting[mid]<target){
                    i=mid+1;
                }else{
                    storeIdx=mid;
                    j=mid-1;
                }
            }
            return storeIdx;
        }
    // LIS (very famous DP Question)
    // int dp[2501][2501]; // we store the index of the prev element not the
    // exact
    //                     // prev element
    // int solve(int i, vector<int>& nums, int prevIndex) {
    //     if (i == nums.size())
    //         return 0; // if index is out of bounds then its LIS is 0
    //     if (prevIndex != -1 && dp[i][prevIndex] != -1)
    //         return dp[i][prevIndex]; // as we have taken indices from -1
    //     // Don't take nums[i]
    //     int skip = solve(i + 1, nums, prevIndex);
    //     // Take nums[i]
    //     int take = 0;
    //     if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
    //         take = 1 + solve(i + 1, nums, i);
    //     }
    //     if (prevIndex != -1)
    //         dp[i][prevIndex] = max(take, skip);  // store in dp state when
    //         the prevIdx is not negative
    //     return max(take, skip);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        // return solve(0, nums, -1); // store the index of the prev element
        // Bottom-Up code  // T.C. is O(N^2)
        int n = nums.size();
        // vector<int> t(n, 1);  // t[i] denotes the LIS ending at the ith index
        // int mx = 1;
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < nums[i]) {
        //             t[i] = max(1 + t[j], t[i]);
        //             mx = max(mx, t[i]);
        //         }
        //     }
        // }
        // return mx;

        // Now suggested Time complexity is O(NlogN) so Do it
        // Patience Sorting T.C. is O(Nlog(N)) but we have to use the
        // lower_bound STL to find the jsut greater than or equal to element or
        // we can also use the BS to find the lower_bound
        // This is by using the built-in lower_bound function best way
        // Now Do the same by using Binary_search to find the lower_bound index 
        vector<int> sorting;
        // for (int i = 0; i < n; i++) {
        //     int pos = lower_bound(sorting.begin(), sorting.end(), nums[i]) - sorting.begin();
        //     if (pos != sorting.size()) {
        //         sorting[pos] = nums[i];
        //     } else {
        //         sorting.push_back(nums[i]);
        //     }
        // }

        for(int el : nums){
            int idx=binary_search_to_find_lower_bound(sorting,el);
            if(idx==-1){
                sorting.push_back(el);
            }else{
                sorting[idx] = el;
            }
        }
        return sorting.size();
    }
};