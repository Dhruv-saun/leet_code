class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<long long> new_coins;
        for (int x : coins) {
            bool redundant = false;
            for (long long y : new_coins) {
                if (x % y == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant)
                new_coins.push_back(x);
        }
        int n = new_coins.size();
        int m = 1 << n;
        vector<long long> lcm(m, 1);
        long long left = k;
        long long right = (long long)new_coins[0] * k + 1;
        for (int mask = 1; mask < m; mask++) {
            int prev_mask = mask & (mask - 1);
            int i = __builtin_ctz(mask);
            long long gcd_val = std::gcd(lcm[prev_mask], new_coins[i]);
            long long tmp = (lcm[prev_mask] / gcd_val) * new_coins[i];
            if (tmp <= right && tmp > 0)
                lcm[mask] = tmp;
            else
                lcm[mask] = right + 1;
        }
        auto count = [&](long long x) {
            long long res = 0;
            for (int mask = 1; mask < m; mask++) {
                if (__builtin_popcount(mask) % 2 == 1)
                    res += x / lcm[mask];
                else
                    res -= x / lcm[mask];
            }
            return res;
        };
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};