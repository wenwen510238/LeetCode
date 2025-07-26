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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }

    void dfs(TreeNode* root, int target, vector<int>& path){
        target -= root->val;
        path.push_back(root->val);

        if(!root->left && !root->right){
            if(target == 0){
                res.push_back(path);
            }
            return;
        } 
        if(root->left){
            dfs(root->left, target, path);
            path.pop_back();
        }
        if(root->right){
            dfs(root->right, target, path);
            path.pop_back();

        }
    }
};