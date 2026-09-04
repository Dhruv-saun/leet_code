class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> stab(nums.size());
        vector<int> suffix(nums.size());
        stab[0]= nums[0];
        for(int i=1;i<nums.size();i++){
            stab[i] = max(stab[i-1], nums[i]);
        }
        suffix[nums.size()-1] = nums[nums.size()-1];

        for(int i = nums.size()-2; i >= 0; i--){
            suffix[i] = min(suffix[i+1], nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(stab[i]-suffix[i]<=k){
                return i;
            }
        }
        return -1;
    }
};