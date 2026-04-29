class Solution {
  public:
  
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &comp) {
        vis[node] = true;
        comp.push_back(node);
        
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, comp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);

        vector<vector<int>> result;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);
                
                sort(comp.begin(), comp.end());
                result.push_back(comp);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};