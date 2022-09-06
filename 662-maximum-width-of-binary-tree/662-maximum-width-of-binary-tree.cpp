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
            
            int n = q.size();
            
            int leftMost = q.front().second;
            int rightMost = q.back().second;
            
            width = max(width, rightMost - leftMost + 1);
            
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, int> tmp = q.front();
                q.pop();
                TreeNode* node = tmp.first;
                int curId = tmp.second - leftMost;
                
                
                if (node->left)
                    q.push({node->left, (long long) 2 * curId + 1});
                if (node->right)
                    q.push({node->right, (long long) 2 * curId + 2});
            }
            
        }
        return width;
    }
};