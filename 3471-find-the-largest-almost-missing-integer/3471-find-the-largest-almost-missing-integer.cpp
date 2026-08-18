class Solution {
public:
    vector <int> subarray(vector<int>&nums,int i, int j){
        vector<int> sub;
        for(int x=i;x<=j;x++){
            sub.push_back(nums[x]);
        }
        return sub;
    }
    int largestInteger(vector<int>& nums, int k) {
        int ans=-1;
        vector <int> freq(51,0);
        vector <int> subArr;
        for(int i=0;i<=nums.size()-k;i++){
            subArr=subarray(nums,i,i+k-1);
            vector<bool> seen(51, false);
            for(int a=0;a<k;a++){
                int x =subArr[a];
                if (!seen[x]){
                    freq[x]++;
                    seen[x]=true;
                }
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]==1)
            {
                ans=max(ans,i);
            }
        }
        return ans;
    }
};