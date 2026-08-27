class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> temp_count = count;
        int max_match = 0;
        while (max_match < n && temp_count[target[max_match] - 'a'] > 0) {
            temp_count[target[max_match] - 'a']--;
            max_match++;
        }

        for (int i = max_match; i >= 0; i--) {
            vector<int> freq = count;
            for (int k = 0; k < i; k++) {
                freq[target[k] - 'a']--;
            }

            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string ans = target.substr(0, i);
                        ans += (char)('a' + c);
                        freq[c]--;

                        for (int ch = 0; ch < 26; ch++) {
                            while (freq[ch] > 0) {
                                ans += (char)('a' + ch);
                                freq[ch]--;
                            }
                        }
                        return ans;
                    }
                }
            }
        }

        return "";
    }
};