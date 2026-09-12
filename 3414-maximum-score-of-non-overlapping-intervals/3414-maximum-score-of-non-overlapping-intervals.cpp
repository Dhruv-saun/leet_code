class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if(a.score != b.score)
            return a.score > b.score;

        return lexicographical_compare(
            a.ids.begin(), a.ids.end(),
            b.ids.begin(), b.ids.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            if(intervals[a][0] != intervals[b][0])
                return intervals[a][0] < intervals[b][0];
            return intervals[a][1] < intervals[b][1];
        });

        vector<int> starts(n);
        for(int i = 0; i < n; i++)
            starts[i] = intervals[order[i]][0];

        vector<int> nxt(n);

        for(int i = 0; i < n; i++) {
            int end = intervals[order[i]][1];
            nxt[i] = upper_bound(starts.begin(), starts.end(), end) - starts.begin();
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for(int i = n - 1; i >= 0; i--) {
            for(int k = 1; k <= 4; k++) {
                State skip = dp[i + 1][k];

                State take = dp[nxt[i]][k - 1];
                take.score += intervals[order[i]][2];
                take.ids.push_back(order[i]);
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].ids;
    }
};