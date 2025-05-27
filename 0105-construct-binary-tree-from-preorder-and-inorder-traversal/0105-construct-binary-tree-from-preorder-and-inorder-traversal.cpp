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
    unordered_map<int, int> inorder_index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorder_index[inorder[i]] = i;
        } 
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size());
    }

    TreeNode* dfs(vector<int>& preorder, int pre_left, int pre_right, vector<int>& inorder, int in_left, int in_right){
        if(pre_left > pre_right)    return nullptr;

        int root_val = preorder[pre_left];
        TreeNode* root = new TreeNode(root_val);

        int idx = inorder_index[root_val];
        int leftLen = idx - in_left; //這個root左邊有多少個node

        root->left = dfs(preorder, pre_left + 1, pre_left + leftLen, inorder, in_left, idx - 1);
        root->right = dfs(preorder, pre_left + leftLen + 1, pre_right , inorder, idx + 1, pre_right);

        return root;

    }
};