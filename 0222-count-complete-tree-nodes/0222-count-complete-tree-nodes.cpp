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
    int getDepth(TreeNode* node, bool isLeft){
        int depth = 0;
        while(node){
            if(isLeft)  node = node->left;
            else    node = node->right;
            depth++;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int l = getDepth(root->left, true);
        int r = getDepth(root->right, false);

        if(l == r)  return pow(2, l+1) - 1;
        else    return 1 + countNodes(root->left) + countNodes(root->right);
    }
};