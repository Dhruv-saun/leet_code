class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;
        int prefix;
        int suffix;
        int best;
        int len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node left, Node right) {

        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;

        res.len = left.len + right.len;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.prefix = left.prefix;
        res.suffix = right.suffix;

        res.best = max(left.best, right.best);

        // The two parts can join
        if (left.rightChar == right.leftChar) {

            // Prefix can extend into right
            if (left.prefix == left.len)
                res.prefix = left.len + right.prefix;

            // Suffix can extend into left
            if (right.suffix == right.len)
                res.suffix = right.len + left.suffix;

            // A repeating sequence crosses the boundary
            res.best = max(res.best,
                           left.suffix + right.prefix);
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, char c) {

        if (l == r) {

            s[index] = c;

            tree[node].leftChar = c;
            tree[node].rightChar = c;

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid)
            update(node * 2, l, mid, index, c);
        else
            update(node * 2 + 1, mid + 1, r, index, c);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};