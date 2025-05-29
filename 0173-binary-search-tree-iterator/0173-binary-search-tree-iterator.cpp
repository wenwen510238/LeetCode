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
class BSTIterator {
public:
    vector<int> vc;
    int current = 0;
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        current++;
        return vc[current-1];
    }
    
    bool hasNext() {
        if(current <= vc.size()-1) return true;
        return false;
    }

    void dfs(TreeNode* node){
        if(!node)   return;
        dfs(node->left);
        vc.push_back(node->val);
        dfs(node->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */