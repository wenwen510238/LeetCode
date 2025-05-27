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
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }   

    bool dfs(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode && !rightNode) return true;
        else if(!leftNode || !rightNode || leftNode->val != rightNode->val)    return false;

        return dfs(leftNode->left, rightNode->right) && dfs(leftNode->right, rightNode->left);
    }
};