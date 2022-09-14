/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& track_parent) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                track_parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                track_parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ios_base::sync_with_stdio(0);
    	cin.tie(nullptr);
    	
        unordered_map<TreeNode* , TreeNode*> track_parent;
        parent(root, track_parent);
        
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        queue<TreeNode* > next_elements;
        next_elements.push(target);
        int curr_level = 0;
        
        while(!next_elements.empty()) {
            if (curr_level++ == k)
                break;
            int n = next_elements.size();
            
            for (int j = 0; j < n; j++) {
                TreeNode* node = next_elements.front();
                next_elements.pop();
                
                if (node->left && !visited[node->left] ) {
                    next_elements.push(node->left);
                    visited[node->left] = true;
                }    
                
                if (node->right && !visited[node->right] ) {
                    next_elements.push(node->right);
                    visited[node->right] = true;
                }
                
                if (track_parent[node] && !visited[track_parent[node] ] ) {
                    next_elements.push(track_parent[node]);
                    visited[track_parent[node] ] = true;
                }
            }
             
        }
        
        vector<int> ans;
        
        while(!next_elements.empty()) {
            ans.push_back(next_elements.front()->val);
            next_elements.pop();
        }
        return ans;
    }
};