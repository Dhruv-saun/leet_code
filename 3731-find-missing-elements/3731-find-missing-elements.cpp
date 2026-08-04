class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minimum = *min_element(nums.begin(),nums.end());
        int maximum = *max_element(nums.begin(),nums.end());
        int size = maximum-minimum+1;
        vector<bool> visit(size,false);
        vector<int> not_found;
        for(int x:nums)
        {
            visit[x-minimum]=true;
        }
        for(int i=0;i<size;i++)
        {
            if(visit[i]==false){
                not_found.push_back(minimum+i);
            }
        }
        return not_found;
    }
};