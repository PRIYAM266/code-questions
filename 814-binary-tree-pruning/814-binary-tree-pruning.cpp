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
    
    TreeNode* helper(TreeNode* node) {
        if (node == NULL)
            return NULL;
        if (node->left)
            node->left = helper(node->left);
        if (node->right)
            node->right = helper(node->right);
        
        if (node->val == 0 && node->left == NULL && node->right == NULL) {
            return NULL;
        }
        return node;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);

        helper(root);
        if (root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;
        return root;
    }
};