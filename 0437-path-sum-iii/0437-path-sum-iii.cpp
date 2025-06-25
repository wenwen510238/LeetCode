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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;
        return dfs(root, targetSum, prefixSum, 0);
    }
    int dfs(TreeNode* node, int target, unordered_map<long long, int>& prefixSum, long long curr){
        if(!node)   return 0;
        
        curr += node->val;
        int cnt = prefixSum[curr - target];
        
        prefixSum[curr]++;

        cnt += dfs(node->left, target, prefixSum, curr) + dfs(node->right, target, prefixSum, curr);

        prefixSum[curr]--;
        return cnt;
    }
};