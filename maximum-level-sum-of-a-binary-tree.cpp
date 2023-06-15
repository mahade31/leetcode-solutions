//problem: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
private:
    int level_sum[10004];
    int max_level;
public:
    void dfs(TreeNode* node, int level) {
        if (node == NULL) return;
        max_level = max(max_level, level);
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
        level_sum[level] += node->val;
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        int ret = 1;
        int mx = level_sum[1];
        for (int i = 2; i <= max_level; ++i) {
            if (level_sum[i] > mx) {
                mx = level_sum[i];
                ret = i;
            }
        }
        return ret;
    }
};
