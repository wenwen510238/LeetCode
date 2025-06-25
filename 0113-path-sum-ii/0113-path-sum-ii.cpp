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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curPath;
        dfs(root, targetSum, res, curPath);
        return res;
    }

    void dfs(TreeNode* root, int targetSum,  vector<vector<int>>& res, vector<int>& curPath){
        if(!root)   return;

        targetSum -= root->val;
        curPath.push_back(root->val);

        if(!root->left && !root->right && targetSum == 0){
            res.push_back(curPath);
        }
        else{
            dfs(root->left, targetSum, res, curPath);
            dfs(root->right, targetSum, res, curPath);
        }
        curPath.pop_back();

    }
};