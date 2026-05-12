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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        if(lca->val == p->val) return p;
        if(lca->val == q->val) return q;
        while(p->val > lca->val == q->val > lca->val){
            if(p->val > lca->val) lca = lca->right;
            else if (p->val < lca->val) lca = lca->left;
            if(lca->val == p->val) return p;
            if(lca->val == q->val) return q;
        }
        return lca;
    }
};
