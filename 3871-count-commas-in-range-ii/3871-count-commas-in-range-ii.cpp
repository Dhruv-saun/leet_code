class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // 4 to 6 digits -> 1 comma
        if (n >= 1000) {
            long long end = min(n, 999999LL);
            ans += end - 1000 + 1;
        }

        // 7 to 9 digits -> 2 commas
        if (n >= 1000000LL) {
            long long end = min(n, 999999999LL);
            ans += (end - 1000000LL + 1) * 2LL;
        }

        // 10 to 12 digits -> 3 commas
        if (n >= 1000000000LL) {
            long long end = min(n, 999999999999LL);
            ans += (end - 1000000000LL + 1) * 3LL;
        }

        // 13 to 15 digits -> 4 commas
        if (n >= 1000000000000LL) {
            long long end = min(n, 999999999999999LL);
            ans += (end - 1000000000000LL + 1) * 4LL;
        }

        // 16 digits -> 5 commas
        if (n >= 1000000000000000LL) {
            ans += (n - 1000000000000000LL + 1) * 5LL;
        }

        return ans;
    }
};