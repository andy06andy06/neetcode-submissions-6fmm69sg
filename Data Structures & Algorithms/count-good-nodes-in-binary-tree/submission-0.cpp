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
   public:
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }

    int dfs(TreeNode* node, int maxval) {
        if (node == nullptr) return 0;
        int ans = (node->val >= maxval) ? 1 : 0;
        
        maxval = max(maxval, node->val);
        ans += dfs(node->left, maxval);
        ans += dfs(node->right, maxval);
        return ans;
    }
};
