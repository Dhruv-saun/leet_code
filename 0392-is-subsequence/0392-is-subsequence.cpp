class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int l=t.length();
        while(j<l){
            if(t[j]==s[i]){
                i++,j++;
            }
            else{
                j++;
            }
        }
        if(i==s.length()) return true;
        return false;
    }
};