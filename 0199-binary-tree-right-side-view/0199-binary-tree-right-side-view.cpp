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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)  return {};
        vector<int> res;
        dfs(root, res, 0);   
        return res;
    }

    void dfs(TreeNode* node, vector<int>& res, int level){
        if(!node)   return;
        if(level == res.size()) res.push_back(node->val);

        level += 1;
        dfs(node->right, res, level);
        dfs(node->left, res, level);
    }
};