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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root, targetSum);
        
    }
    bool dfs(TreeNode* node, int target){
        if(!node->left && !node->right && target-node->val == 0)    return true;
        else if(!node->left && !node->right)  return false;
        target -= node->val;
        
        if(node->left && node->right)  return dfs(node->left, target) || dfs(node->right, target);
        else if(node->left) return dfs(node-> left, target);
        else return dfs(node->right, target);
    }
};