class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        auto build = [&](string left) {
            string res = left;

            if (n % 2)
                res += mid;

            reverse(left.begin(), left.end());
            res += left;

            return res;
        };

        string left;

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';

            if (half[c] == 0)
                break;

            half[c]--;
            left += target[i];
        }

        if (left.size() == m) {
            string candidate = build(left);

            if (candidate > target)
                return candidate;
        }

        for (int i = min((int)left.size(), m - 1); i >= 0; i--) {
            if (i < left.size())
                half[left[i] - 'a']++;

            int c = target[i] - 'a';

            for (int j = c + 1; j < 26; j++) {
                if (half[j] == 0)
                    continue;

                half[j]--;

                string newLeft = target.substr(0, i);
                newLeft += char('a' + j);

                for (int x = 0; x < 26; x++)
                    newLeft += string(half[x], char('a' + x));

                return build(newLeft);
            }
        }

        return "";
    }
};