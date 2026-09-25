class Solution {
public:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> temp = parseTerm();
            res.insert(temp.begin(), temp.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur;

            if (s[pos] == '{') {
                pos++;
                cur = parseExpression();
                pos++;
            } else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            set<string> next;

            for (auto &a : res)
                for (auto &b : cur)
                    next.insert(a + b);

            res = next;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};