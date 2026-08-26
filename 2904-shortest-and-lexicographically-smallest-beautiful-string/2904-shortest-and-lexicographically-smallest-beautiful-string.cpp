class Solution {
public:
    string lexicographically_smallest(string str1,string str2){
        if(str1.length()!=str2.length()){
            return str1.length()<str2.length()?str1:str2;
        }
        for(int i=0;i<str1.length();i++){
            if(str1[i]==str2[i]) continue;
            else if(str1[i]<str2[i]) {return str1;}
            else return str2;
        }
        return str1;
    }
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        string candidate = "";
        int minLen = INT_MAX;
        int count = 0,left = 0 ,right = 0,n = s.length();
        while(right<n){
            while(right<n&&count<k){
                if(s[right]=='1') count++;
                right++;
            }
            if(count<k) break;
            while(left<right && s[left]=='0') left++;
            string candidate = s.substr(left,right-left);
            if(candidate.length()<minLen){
                ans = candidate;
                minLen = ans.length();
            }else if(candidate.length()==minLen){
                ans = lexicographically_smallest(ans,candidate);
            }
            count--;
            left++;
        }
        return ans;
    }
};