class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0,minprice=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            if(minprice>prices[i]) minprice= prices[i];
            else
            {
                int profit= prices[i]-minprice;
                if(profit>maxpro)
                    maxpro=profit;
            }
        }
        return maxpro;
    }
};