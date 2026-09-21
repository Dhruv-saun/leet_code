class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            int rem = num % k;
            vector<long long> next(k, 0);
            next[rem] = 1;
            for (int j = 0; j < k; j++) {
                if (dp[j] > 0) {
                    int newRem = (j * rem) % k;
                    next[newRem] += dp[j];
                }
            }
            for (int j = 0; j < k; j++) {
                ans[j] += next[j];
            }
            dp = next;
        }
        return ans;
    }
};