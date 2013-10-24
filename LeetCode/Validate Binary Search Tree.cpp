// Validate Binary Search Tree  

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
    bool isValidBST(TreeNode *root) {
        vector<int> vec;
        travel(root, vec);
        for(int i = 0, j = 1; j < vec.size(); ++i, ++j) {
            if(vec[j] <= vec[i]) return false;
        }
        return true;
    }
    
    void travel(TreeNode *root, vector<int> &vec) {
        if(root) {
            travel(root->left, vec);
            vec.push_back(root->val);
            travel(root->right, vec);
        }
    }
};