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
    vector<int> rightSideView(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp; // y, value
        queue<pair<TreeNode*, int>> q; // node, y
        q.push({root, 0});
        while(!q.empty()) {
            pair<TreeNode*, int> tmp = q.front();
            q.pop();
            TreeNode* node = tmp.first;
            int y = tmp.second;
            mp[y] = node->val;
            if (node->left)
                q.push({node->left, y+1});
            if (node->right)
                q.push({node->right, y+1});
        }
        for (auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};