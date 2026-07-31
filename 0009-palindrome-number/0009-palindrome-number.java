class Solution {
    public boolean isPalindrome(int x) {
        int rev=0,real=x;
        while(x>0){
            int rem=x%10;
            rev=(rev*10)+rem;
            x=x/10;
        }
        if(rev==real) return true;
        return false;
    }
}