class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstLargest=LLONG_MIN, secondLargest=LLONG_MIN, thirdLargest = LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==firstLargest||nums[i]==secondLargest||nums[i]==thirdLargest) continue;
            if(nums[i]>firstLargest){
                thirdLargest=secondLargest;
                secondLargest=firstLargest;
                firstLargest=nums[i];
            }else if(nums[i]>secondLargest&&nums[i]<firstLargest){
                thirdLargest=secondLargest;
                secondLargest=nums[i];
            }
            else if(nums[i]>thirdLargest)
                thirdLargest = nums[i];
        }
        if(firstLargest==LLONG_MIN||secondLargest==LLONG_MIN||thirdLargest==LLONG_MIN){
            return firstLargest;
        }
        return thirdLargest;
    }
};