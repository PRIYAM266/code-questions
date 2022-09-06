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
    
    void helper(TreeNode* node, string curr, vector<string>& ans) {
        if (node == NULL)
            return;
        if (node->left || node->right) {
            curr += to_string(node->val) + "->";
        } else {
            curr += to_string(node->val);
            ans.push_back(curr);
        }
        helper(node->left, curr, ans);
        helper(node->right, curr, ans);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        vector<string> ans;
        if (root == NULL)
            return ans;
        string curr = "";
        helper(root, curr, ans);
        return ans;
    }
};