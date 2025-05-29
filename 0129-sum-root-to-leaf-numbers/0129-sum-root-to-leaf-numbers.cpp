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
    int sumNumbers(TreeNode* root) {
        vector<int> res;
        int ans = 0;
        dfs(root, res, 0);

        for(int i=0; i<res.size(); i++){
            ans += res[i];
        }
        return ans;
    }
    void dfs(TreeNode* node, vector<int>& res, int currentSum){
        currentSum = currentSum * 10 + node->val;
        if(!node->left && !node->right) res.push_back(currentSum);

        if(node->left)  dfs(node->left, res, currentSum);
        if(node->right)  dfs(node->right, res, currentSum);
    }
};