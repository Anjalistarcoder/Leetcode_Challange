class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
    
        vector<int> color(n, -1);
    
        for (int i = 0; i < n; i++) {
            
            if (color[i] != -1)
                continue;
    
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                
                int node = q.front();
                q.pop();
                
                // Visit all neighbours
                for (int neighbour : graph[node]) {
                    
                    // If neighbour is not colored
                    if (color[neighbour] == -1) {
                        
                        // Give opposite color
                        color[neighbour] = 1 - color[node];
                        q.push(neighbour);
                    }
                    
                    // If both have same color
                    else if (color[neighbour] == color[node]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};