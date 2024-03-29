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
    
    bool symmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL)
            return left == right;
        
        else if (left->val != right->val)
            return false;
        
        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        return root == NULL || symmetric(root->left, root->right);
    }
};