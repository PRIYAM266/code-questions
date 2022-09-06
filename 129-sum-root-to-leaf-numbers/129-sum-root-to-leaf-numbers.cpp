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
    
    void path(TreeNode* node, string curr, vector<string>& v) {
        if (node->left == NULL && node->right == NULL) {
            curr += to_string(node->val);
            v.push_back(curr);
        }
        curr += to_string(node->val);
        if (node->left)
            path(node->left, curr, v);
        if (node->right)
            path(node->right, curr, v);
    }
    
    int sumNumbers(TreeNode* root) {
        vector<string> v;
        string curr = "";
        path(root, curr, v);
        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans += stoi(v[i]);
        }
        return ans;
    }
};