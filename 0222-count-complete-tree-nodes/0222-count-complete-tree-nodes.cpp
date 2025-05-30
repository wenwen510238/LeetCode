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
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        else if(!root->left && !root->right)    return 1;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            level++;
            int n = q.size();
            int child = 0;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left) return pow(2, level)-1+child;
                else if(!node->right)   return pow(2, level)-1+child+1;
                q.push(node->left);
                q.push(node->right);
                child += 2;
            }
        }
        return pow(2, level)-1;
    }
};