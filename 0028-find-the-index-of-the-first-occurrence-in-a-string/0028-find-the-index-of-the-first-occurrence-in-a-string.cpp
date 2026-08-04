class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0) return 0;
        if (needle.length() > haystack.length())
            return -1;
        int i=0;
        while(i<=haystack.length()-needle.length()){
            if(haystack[i]==needle[0]){
                int p=i;
                int k=0;
                while(k<needle.length()){
                    if(needle[k]==haystack[p])
                    {
                        k++, p++;
                        continue;
                    }else break;
                }
                if(k<needle.length()) i++;
                else return i;
            }else{i++;}
        }
        return -1;
    }
};