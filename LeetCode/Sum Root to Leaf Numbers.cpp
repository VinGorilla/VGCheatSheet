// Sum Root to Leaf Numbers

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int ret = 0;
        sum(root, 0, ret);
        return ret;
    }
    
    void sum(TreeNode *root, int up, int &ret) {
        if(!root) return;
        int val = up * 10 + root->val;
        if(!root->left && !root->right) {ret += val; return;}
        sum(root->left, val, ret);
        sum(root->right, val, ret);
    }
};