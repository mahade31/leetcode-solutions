//problem: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
vector <int> vec[1003];
vector <int> ret;
int vis[1003];
public:
    void dfs(int u, int level, int k) {
        if (vis[u]) return;
        vis[u] = true;
        if (level == k) {
            ret.push_back(u);
            return;
        }
        for (int v : vec[u]) {
            dfs(v, level + 1, k);
        }
    }
    void makeTree(TreeNode* root) {
        if (root == NULL) return;
        if (root -> left) {
            vec[root -> val].push_back(root -> left -> val);
            vec[root -> left -> val].push_back(root -> val);
            makeTree(root -> left);
        }
        if (root -> right) {
            vec[root -> val].push_back(root -> right -> val);
            vec[root -> right -> val].push_back(root -> val);
            makeTree(root -> right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeTree(root);
        dfs(target -> val, 0, k);
        return ret;
    }
};
