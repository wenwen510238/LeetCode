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
    unordered_map<int, int> inorder_idx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            inorder_idx[inorder[i]] = i;
        }

        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int post_left, int post_right){
        if(post_left > post_right)  return nullptr;
        
        int val = postorder[post_right];
        TreeNode* root = new TreeNode(val);

        int rightLen = in_right - inorder_idx[val];

        root->right = buildTree(inorder, inorder_idx[val] + 1, in_right, postorder, post_right - rightLen, post_right - 1);
        root->left = buildTree(inorder, in_left, inorder_idx[val] - 1, postorder, post_left, post_right - rightLen - 1);

        return root;
    }
};

// inorder:  17 5 9 6 3 15 20 7
// postorder 17 5 6 9 15 7 20 3