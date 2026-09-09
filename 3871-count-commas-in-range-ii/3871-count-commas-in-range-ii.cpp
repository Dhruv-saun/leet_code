class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (n >= 1000) {
            long long end = min(n, 999999LL);
            ans += end - 1000 + 1;
        }
        if (n >= 1000000LL) {
            long long end = min(n, 999999999LL);
            ans += (end - 1000000LL + 1) * 2LL;
        }
        if (n >= 1000000000LL) {
            long long end = min(n, 999999999999LL);
            ans += (end - 1000000000LL + 1) * 3LL;
        }
        if (n >= 1000000000000LL) {
            long long end = min(n, 999999999999999LL);
            ans += (end - 1000000000000LL + 1) * 4LL;
        }
        if (n >= 1000000000000000LL) {
            ans += (n - 1000000000000000LL + 1) * 5LL;
        }
        return ans;
    }
};