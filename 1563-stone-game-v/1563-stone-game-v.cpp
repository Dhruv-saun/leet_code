class Solution {
public:
    vector<int> prefixSum;
    int solve(int left, int right, vector<vector<int>>&dp){
        if(left==right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int ans =0, leftSum=0,rightSum=0;
        for(int i=left;i<right;i++){
            leftSum=prefixSum[i+1]-prefixSum[left];
            rightSum= prefixSum[right+1]-prefixSum[i+1];
            if(leftSum<rightSum){
                ans= max(ans, leftSum+solve(left,i,dp));
            }else if(leftSum>rightSum){
                ans=max(ans,rightSum+solve(i+1,right,dp));
            }else{
                ans=max(ans,max(leftSum+solve(left,i,dp),rightSum+solve(i+1,right,dp)));
            }
        }
        dp[left][right]= ans;
        return ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        prefixSum.assign(n + 1, 0);
        for(int i=0;i<stoneValue.size();i++){
            prefixSum[i+1] = prefixSum[i]+stoneValue[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,stoneValue.size()-1,dp);
    }
};