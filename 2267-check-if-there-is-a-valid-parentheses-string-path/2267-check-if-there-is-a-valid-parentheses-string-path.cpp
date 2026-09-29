class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // dp[j] = set of reachable balances at column j of the current row
        vector<bitset<202>> dp(n);
        dp[0][1] = 1;  // after the first '(' the balance is 1

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                bitset<202> mask;
                if (i > 0) mask |= dp[j];      // from above (previous row, not yet overwritten)
                if (j > 0) mask |= dp[j - 1];  // from the left (current row, already updated)
                dp[j] = (grid[i][j] == '(') ? (mask << 1) : (mask >> 1);
            }
        }
        return dp[n - 1][0];
    }
};