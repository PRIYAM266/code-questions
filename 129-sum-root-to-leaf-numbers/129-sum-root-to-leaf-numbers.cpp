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
    void path(TreeNode* node, int tmp, int& ans) {
        if (node == NULL)
            return;
        
        tmp = tmp * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            ans += tmp;
        }
        
        if (node->left)
            path(node->left, tmp, ans);
        if (node->right)
            path(node->right, tmp, ans);
    }
    
    int sumNumbers(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        int ans = 0;
        path(root, 0, ans);
        
        // for (int i = 0; i < v.size(); i++) {
        //     ans += stoi(v[i]);
        // }
        return ans;
    }
};