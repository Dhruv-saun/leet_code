class Solution {
public:
    int helper(vector<int>& piles, vector<vector<int>>& dp,
               const vector<int>& suffixSum, int i, int M) {
        int n = piles.size();
        if (i == n)
            return 0;
        if (i + 2 * M >= n)
            return suffixSum[i];
        if (dp[i][M] != -1)
            return dp[i][M];
        int result = 0;
        for (int x = 1; x <= 2 * M; x++) {
            result = max(result,
                         suffixSum[i] -
                         helper(piles, dp, suffixSum,
                                i + x, max(M, x)));
        }
        return dp[i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> suffixSum(n);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = piles[i] + suffixSum[i + 1];
        }
        return helper(piles, dp, suffixSum, 0, 1);
    }
};