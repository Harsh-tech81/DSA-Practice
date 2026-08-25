class Solution {
public:
    // unordered_map<string,int>mp;
    //     int solve(int i, int prev, string& s, int& k) {
    //         if (i >= s.length())
    //             return 0;
    //             string key=to_string(prev)+" "+to_string(i);
    //             if(mp.count(key)) return mp[key];
    //         int skip = solve(i + 1, prev, s, k);
    //         int take = 0;
    //         if (prev == -1 || abs(s[i] - s[prev]) <= k) {
    //             take = 1 + solve(i + 1, i, s, k);
    //         }
    //         return mp[key]= max(skip, take);
    //     }
    int longestIdealString(string s, int k) {

        // return solve(0, -1, s, k);
        int n = s.length();
        // int mx=1;
        // vector<int> t(n, 1);
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (abs(s[i] - s[j]) <= k) {
        //             t[i] = max(t[i], 1 + t[j]);
        //             mx = max(mx, t[i]);
        //         }
        //     }
        // }
        // return mx;

        // Both of its Top-Down and Bottom-Up approach gives TLE so How could I
        // proceed
        // This step is very IMP How could I optimize so that it submitted
        vector<int> frq(26, 0); // freq vector of all the characters 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a'; 
            int st = max(0, idx - k);
            int end = min(25, idx + k);
            int mx = 0;
            for (int i = st; i <= end; i++) { // possible values of the alphabets m max-value kaun s hogi 
                mx = max(mx, frq[i]);
            }
            frq[idx] = 1 + mx; // plus that one character (ith index tkk max. subsequence valid k length)
            ans = max(ans, frq[idx]);
        }
        return ans;
    }
};