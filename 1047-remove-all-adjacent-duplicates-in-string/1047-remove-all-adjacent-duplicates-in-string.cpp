class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> s1;
        s1.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(!s1.empty()&&s1.top()==s[i])
            {
                s1.pop();
            }else{
                s1.push(s[i]);
            }
        }
        string t="";
        while(!s1.empty()){
            t+=s1.top();
            s1.pop();
        }
        reverse(t.begin(), t.end());
        return t;
    }
};