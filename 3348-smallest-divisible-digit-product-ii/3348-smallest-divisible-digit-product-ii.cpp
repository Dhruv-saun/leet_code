class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        while (temp % 2 == 0) { req2++; temp /= 2; }
        while (temp % 3 == 0) { req3++; temp /= 3; }
        while (temp % 5 == 0) { req5++; temp /= 5; }
        while (temp % 7 == 0) { req7++; temp /= 7; }
        
        if (temp > 1) return "-1";

        int n = num.length();
        
        auto get_min_digits_needed = [](int r2, int r3, int r5, int r7) {
            int digits = 0;
            digits += r7;
            digits += r5;
            digits += (r3 + 1) / 2; 
            int rem3 = r3 % 2;
            if (rem3 == 1 && r2 >= 1) {
                r2 -= 1;
            }
            digits += (r2 + 2) / 3;
            return digits;
        };

        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        int first_zero = -1;

        for (int i = 0; i < n; ++i) {
            p2[i + 1] = p2[i]; p3[i + 1] = p3[i]; p5[i + 1] = p5[i]; p7[i + 1] = p7[i];
            if (num[i] == '0') {
                if (first_zero == -1) first_zero = i;
                continue;
            }
            int d = num[i] - '0';
            while (d % 2 == 0) { p2[i + 1]++; d /= 2; }
            while (d % 3 == 0) { p3[i + 1]++; d /= 3; }
            while (d % 5 == 0) { p5[i + 1]++; d /= 5; }
            while (d % 7 == 0) { p7[i + 1]++; d /= 7; }
        }

        if (first_zero == -1 && p2[n] >= req2 && p3[n] >= req3 && p5[n] >= req5 && p7[n] >= req7) {
            return num;
        }

        int limit = (first_zero != -1) ? first_zero : n - 1;
        for (int i = limit; i >= 0; --i) {
            int start_digit = (num[i] - '0') + 1;
            if (first_zero != -1 && i == first_zero) start_digit = 1;

            for (int d = start_digit; d <= 9; ++d) {
                int cur2 = p2[i], cur3 = p3[i], cur5 = p5[i], cur7 = p7[i];
                int val = d;
                while (val % 2 == 0) { cur2++; val /= 2; }
                while (val % 3 == 0) { cur3++; val /= 3; }
                while (val % 5 == 0) { cur5++; val /= 5; }
                while (val % 7 == 0) { cur7++; val /= 7; }

                int rem2 = max(0, req2 - cur2);
                int rem3 = max(0, req3 - cur3);
                int rem5 = max(0, req5 - cur5);
                int rem7 = max(0, req7 - cur7);

                int rem_len = n - 1 - i;
                if (get_min_digits_needed(rem2, rem3, rem5, rem7) <= rem_len) {
                    string ans = num.substr(0, i) + to_string(d);
                    string suffix = "";
                    while (rem7 > 0) { suffix += '7'; rem7--; }
                    while (rem5 > 0) { suffix += '5'; rem5--; }
                    while (rem3 >= 2) { suffix += '9'; rem3 -= 2; }
                    while (rem2 >= 3) { suffix += '8'; rem2 -= 3; }
                    if (rem3 == 1 && rem2 >= 1) { suffix += '6'; rem3--; rem2--; }
                    if (rem2 == 2) { suffix += '4'; rem2 -= 2; }
                    if (rem3 == 1) { suffix += '3'; rem3--; }
                    if (rem2 == 1) { suffix += '2'; rem2--; }

                    while (suffix.length() < rem_len) {
                        suffix += '1';
                    }
                    sort(suffix.begin(), suffix.end());
                    return ans + suffix;
                }
            }
        }

        int target_len = max((int)num.length() + 1, get_min_digits_needed(req2, req3, req5, req7));
        string suffix = "";
        while (req7 > 0) { suffix += '7'; req7--; }
        while (req5 > 0) { suffix += '5'; req5--; }
        while (req3 >= 2) { suffix += '9'; req3 -= 2; }
        while (req2 >= 3) { suffix += '8'; req2 -= 3; }
        if (req3 == 1 && req2 >= 1) { suffix += '6'; req3--; req2--; }
        if (req2 == 2) { suffix += '4'; req2 -= 2; }
        if (req3 == 1) { suffix += '3'; req3--; }
        if (req2 == 1) { suffix += '2'; req2--; }

        while (suffix.length() < target_len) {
            suffix += '1';
        }
        sort(suffix.begin(), suffix.end());
        return suffix;
    }
};
