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
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        vector<string> res;
        dfs(root, res, s);
        return res;
    }
    void dfs(TreeNode* node, vector<string>& res, string s){
        if(!node)   return;
        s += to_string(node->val);

        if(!node->left && !node->right) res.push_back(s);
        if(node->left) dfs(node->left, res, s+"->");
        if(node->right) dfs(node->right, res, s+"->");
        
    }   
};