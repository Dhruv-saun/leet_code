class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n= word1.length();
        int m = word2.length();
        vector<int> last(m,-1);
        for(int i=n-1,j=m-1;i>=0 && j>=0;--i){
            if(word1[i]==word2[j]){
                last[j]=i;
                --j;
            }
        }
        vector<int>ans(m);
        bool canChange = true;
        int j=0;
        for(int i=0;i<n&&j<m;++i){
            if(word1[i] == word2[j]){
                ans[j++]=i;
            }else if(canChange &&(j == m-1||i<last[j+1])){
                ans[j++]=i;
                canChange=false;
            }
            if(j==m) return ans;
        }
        return vector<int>();
    }
};