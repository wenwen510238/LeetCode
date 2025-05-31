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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool leftToRight = true;

        q.push(root);
        while(!q.empty()){
            int n = q.size(), idx;
            vector<int> level(n);

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(leftToRight) idx = i;
                else   idx = n-i-1;

                level[idx] = node->val;

                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};