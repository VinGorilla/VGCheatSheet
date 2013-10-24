// Unique Binary Search Trees II

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
    vector<TreeNode *> generateTrees(int n) {
        int a[n];
        for(int i = 0; i < n; ++i) a[i] = i+1;
        return generate(a, 0, n-1);
    }
    
    vector<TreeNode *> generate(int a[], int l, int h) {
        vector<TreeNode *> ret;
        if(h < l) {ret.push_back(NULL); return ret;}
        if(l == h) {ret.push_back(new TreeNode(a[l])); return ret;}
        for(int i = l; i <= h; ++i) {
            vector<TreeNode *> vec1 = generate(a, l, i-1);
            vector<TreeNode *> vec2 = generate(a, i+1, h);
            for(int j = 0; j < vec1.size(); ++j) {
                for(int k = 0; k < vec2.size(); ++k) {
                    TreeNode *node = new TreeNode(a[i]);
                    node->left = vec1[j];
                    node->right = vec2[k];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
};