class Solution {
    public int climbStairs(int n) {
        if(n<=2)
            return n;
        int twoback=1;
        int oneback=2;
        for(int i=3;i<=n;i++)
        {
            int current=twoback+oneback;
            twoback=oneback;
            oneback=current;
        }
        return oneback;
    }
}