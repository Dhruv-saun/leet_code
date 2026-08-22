class Solution {
public:
    int digit_sum(int n){
        int sum = 0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }return sum;
    }
    int product(int n){
        int prod = 1;
        while(n>0){
            prod*=n%10;
            n/=10;
        }return prod;
    }
    bool checkDivisibility(int n) {
        return n%(digit_sum(n)+product(n))==0;
    }
};