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
    unordered_map<int, int> inorderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size()-1, inorder, 0);
    }

    TreeNode* dfs(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft){
        if(preLeft > preRight)  return nullptr;

        int val = preorder[preLeft];
        TreeNode* node = new TreeNode(val);

        int inorderIdx = inorderMap[val];
        int len = inorderIdx - inLeft;

        node->left = dfs(preorder, preLeft + 1, preLeft + len, inorder, inLeft);
        node->right = dfs(preorder, preLeft + len + 1, preRight, inorder, inorderIdx + 1);
        return node;
    }
};