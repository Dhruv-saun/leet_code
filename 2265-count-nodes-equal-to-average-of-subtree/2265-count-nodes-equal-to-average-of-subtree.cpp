/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int matchingNodesCount = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }

        auto leftResult = dfs(node->left);
        auto rightResult = dfs(node->right);

        int currentSum = leftResult.first + rightResult.first + node->val;
        int currentCount = leftResult.second + rightResult.second + 1;

        if (currentSum / currentCount == node->val) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodesCount = 0;
        dfs(root);
        return matchingNodesCount;
    }
};