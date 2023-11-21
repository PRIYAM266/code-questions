class Solution {
public:
    vector<vector<int>> adjList(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        return adj;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto it: adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj = adjList(isConnected);
        vector<int> vis(n + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
};