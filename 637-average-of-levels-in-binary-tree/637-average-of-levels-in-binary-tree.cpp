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
    vector<double> averageOfLevels(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        vector<double> ans;
        if (root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> row;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            double sum = 0;
            for (int i = 0; i < row.size(); i++) {
                sum += row[i];
            }
            ans.push_back(sum / row.size());
        }
        return ans;
    }
};