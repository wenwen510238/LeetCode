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
    int getMinimumDifference(TreeNode* root) {
        vector<int> vc;
        inOrder(root, vc);
        int res = INT_MAX;
        for(int i=1; i<vc.size(); i++){
            res = min(res, abs(vc[i]-vc[i-1]));
        }
        return res;
    }
    void inOrder(TreeNode* root, vector<int>& vc){
        if(!root)   return ;
        inOrder(root->left, vc);
        vc.push_back(root->val);
        inOrder(root->right, vc);
    }

};
//         236
//   104        701
//       227         911