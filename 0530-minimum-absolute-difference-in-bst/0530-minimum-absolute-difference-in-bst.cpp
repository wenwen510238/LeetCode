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
    int minNum = INT_MAX;
    TreeNode* prev = nullptr;
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minNum;
    }
    void inOrder(TreeNode* root){
        if(!root)   return ;

        inOrder(root->left);

        if(prev)    minNum = min(minNum, abs(root->val - prev->val));
        
        prev = root;
        inOrder(root->right);
    }

};