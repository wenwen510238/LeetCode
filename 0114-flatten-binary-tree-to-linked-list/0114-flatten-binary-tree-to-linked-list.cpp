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
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        dfs(root, prev);
    }
    void dfs(TreeNode* node, TreeNode*& prev){
        if(!node)   return ;

        dfs(node->right, prev);
        dfs(node->left, prev);

        node->right = prev;
        node->left = nullptr;

        prev = node;
    }
};