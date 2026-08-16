class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0=0,count1=0,count2=0;
        for(int value: stones){
            if(value%3==0) count0++;
            else if(value%3==1) count1++;
            else count2++;
        }
        if(count0%2==0)
        {
            return count1>=1 && count2>=1;
        }
        return count1-count2>2 ||count2-count1>2;
    }
};