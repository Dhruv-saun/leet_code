class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, true));
        vector<int> dp(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                pal[i][j] = s[i] == s[j] && pal[i + 1][j - 1];
            }
        }
        function<int(int)> solve = [&](int i) {
            if (i >= n)
                return 0;
            if (dp[i] != -1)
                return dp[i];
            int ans = solve(i + 1);
            for (int j = i + k - 1; j < n; j++) {
                if (pal[i][j]) {
                    ans = max(ans, 1 + solve(j + 1));
                }
            }
            return dp[i] = ans;
        };
        return solve(0);
    }
};