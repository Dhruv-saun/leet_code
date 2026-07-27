class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=0,max2=0;
        for(int n: nums){
            if(n>max1){
                max2=max1;
                max1=n;
            }else if(max2<n){
                max2=n;
            }
        }
        return (max1-1)*(max2-1);
    }
};