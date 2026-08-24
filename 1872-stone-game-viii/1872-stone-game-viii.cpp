class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n);
        prefix[0]=stones[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = stones[i]+prefix[i-1];
        }
        int dp = prefix[n-1];
        for(int i = n-2;i>=1;--i){
            dp = max(dp,prefix[i]-dp);
        }
        return dp;
    }
};