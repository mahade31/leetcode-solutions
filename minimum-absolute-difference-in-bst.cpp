//problem: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int mn = 1e9;
    int last_val = 1e9;
public:
    void in_order_traverse(TreeNode* root) {
        if (root == NULL) return;
        in_order_traverse(root->left);
        mn = min(abs(last_val - root->val), mn);
        last_val = root->val;
        in_order_traverse(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        in_order_traverse(root);
        return mn;
    }
};
