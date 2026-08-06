class Solution {
public:
    int current_product(int n){
        int product=1;
        while(n>0){
            product*=n%10;
            n/=10;
        }
        return product;

    }
    int smallestNumber(int n, int t) {
        while (true){
            if(current_product(n)%t==0) return n;
            n++;
        }
    }
};