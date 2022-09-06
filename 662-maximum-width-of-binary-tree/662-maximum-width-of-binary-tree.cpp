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
    int widthOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        
        int width = 0;
        if (root == NULL) return width;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            int curMin = q.front().second;
            int n = q.size();
            int leftMost, rightMost;
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, int> tmp = q.front();
                q.pop();
                TreeNode* node = tmp.first;
                int curId = tmp.second - curMin;
                if (i == 0)
                    leftMost = curId;
                if (i == n - 1)
                    rightMost = curId;
                
                if (node->left)
                    q.push({node->left, (long long) 2 * curId + 1});
                if (node->right)
                    q.push({node->right, (long long) 2 * curId + 2});
            }
            width = max(width, rightMost - leftMost + 1);
        }
        return width;
    }
};