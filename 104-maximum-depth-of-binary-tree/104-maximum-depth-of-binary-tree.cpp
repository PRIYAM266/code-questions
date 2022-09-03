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
    
    int f(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = f(root->left);
        int rh = f(root->right);
        
        return 1 + max(lh, rh);
    }
    
    int maxDepth(TreeNode* root) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
//         if (root == NULL) return 0;
//         int depth = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//             int n = q.size();
//             depth++;
//             for (int i = 0; i < n; i++) {
//                 TreeNode* tmp = q.front();
//                 q.pop();
                
//                 if (tmp->left)
//                     q.push(tmp->left);
//                 if (tmp->right)
//                     q.push(tmp->right);
//             }
//         }
//         return depth;
        return f(root);
    }
};