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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        int res = 1;
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            unsigned long long idx_start = -1, idx_end = -1;
            for(int i=0; i<size; i++){
                auto [node, idx] = q.front();
                q.pop();
                if(i == 0) idx_start = idx;
                else if(i == size - 1)  idx_end = idx;
                
                if(node->left) q.push({node->left, idx*2 + 1}); 
                if(node->right) q.push({node->right, idx*2 + 2}); 
            }
            if(idx_start!=-1 && idx_end!=-1) res = max(res, (int)(idx_end - idx_start + 1));
        }
        return res;
    }
};

//       0
//    1      2
//  3   4   5  6
// 7 8 9 10 

//   4
//  2  
// 1 3