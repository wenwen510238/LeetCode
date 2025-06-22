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
    int rob(TreeNode* root) {
        auto [hasRoot, notRoot] = dfs(root);
        return max(hasRoot, notRoot);
    }
    pair<int, int> dfs(TreeNode* node){
        if(!node)   return {0, 0};

        auto [lHasR, lNotR] = dfs(node->left);
        auto [rHasR, rNotR] = dfs(node->right);

        int hasRoot = node->val + lNotR + rNotR;
        int notRoot = max(lHasR, lNotR) + max(rHasR, rNotR) ;
        return {hasRoot, notRoot};
    }
};