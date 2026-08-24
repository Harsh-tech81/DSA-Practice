class Solution {
public:
    bool checkSubsequence(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else
                j++;
        }
        return i == s1.length() ? true : false;
    }
    static bool cmp(string& a, string& b) {
        if (a.length() == b.length())
            return a[0] < b[0];
        return a.length() < b.length();
    }
    int dp[1001][1001];
    int solve(int i, vector<string>& words, int prev) {
        if (i >= words.size())
            return 0;
        if (prev != -1 && dp[i][prev] != -1)
            return dp[i][prev];
        int skip = solve(i + 1, words, prev);
        int take = 0;
        if (prev == -1 || (words[i].length() == words[prev].length() + 1 &&
                           checkSubsequence(words[prev], words[i]))) {
            take = 1 + solve(i + 1, words, i);
        }
        if (prev != -1)
            dp[i][prev] = max(skip, take);
        return max(skip, take);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        memset(dp, -1, sizeof(dp));
        return solve(0, words, -1);
        return 0;
    }
};