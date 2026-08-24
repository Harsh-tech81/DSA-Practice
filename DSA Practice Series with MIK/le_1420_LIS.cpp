class Solution {
public:
    // This is also one of the variant of LIS
    // here LIS length is already given is k(which is fixed )
    // we have to make our own array so that its LIS is k
    // array is also not given from where we have to find the LIS elements
    int dp[51][51][101];
    int mod = 1e9 + 7;
    int solve(int i, int n, int m, int k, int cost, int mx) {
        if (i >= n) {
            if (cost == k)
                return 1;
            return 0;
        }
        if (dp[i][cost][mx] != -1)
            return dp[i][cost][mx];
        int ans = 0;
        for (int el = 1; el <= m; el++) {
            if (el > mx) {
                ans = (ans + solve(i + 1, n, m, k, cost + 1, el) ) %
                      mod;
            } else {
                ans = (ans + solve(i + 1, n, m, k, cost, mx) ) % mod;
            }
        }
        return dp[i][cost][mx] = ans;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, m, k, 0, 0);
    }
};