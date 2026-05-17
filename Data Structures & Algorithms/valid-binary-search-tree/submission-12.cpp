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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MAX, LONG_MIN);
    }
    int dfs(TreeNode* node, long maxval, long minval){
        if(node==nullptr) return 1;
        
        if(maxval <= node->val || minval >= node->val) return 0;
        
        return dfs(node->left, node->val, minval) && dfs(node->right, maxval, node->val);
    }
};
