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
            int n = q.size();
            deque<int> deq;

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(leftToRight) deq.push_back(node->val); 
                else    deq.push_front(node->val);

                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
            res.push_back(vector<int>(deq.begin(), deq.end()));
            leftToRight = !leftToRight;
        }
        return res;
    }
};