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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        dfs(root, res, k);
        return res[k-1];
    }

    void dfs(TreeNode* node, vector<int>& res, int k){
        if(node==nullptr) return;
        
        dfs(node->left, res, k);
        res.push_back(node->val);
        dfs(node->right, res, k);
        if(res.size()==k) return;
    }
};
