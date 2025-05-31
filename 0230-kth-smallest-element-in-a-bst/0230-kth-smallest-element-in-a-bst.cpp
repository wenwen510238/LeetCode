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
    int cnt = 0;
    int res = -1;
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return res;      
    }
    void inOrder(TreeNode* node, int k){
        if(!node || res != -1)   return;
        inOrder(node->left, k);
        
        cnt++;
        if(cnt == k){
            res = node->val;
            return;
        }

        inOrder(node->right, k);
    }
};