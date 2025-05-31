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
        if(!root)   return {};
        queue<TreeNode*> q;
        vector<int> res;

        q.push(root);
    
        while(!q.empty()){
            int n = q.size();

            for(int i=0; i<n; i++){
                TreeNode* current = q.front();
                q.pop();
                if(i == 0)   res.push_back(current->val);
                if(current->right)  q.push(current->right);
                if(current->left)  q.push(current->left);
            }
        }
        return res;
    }
};