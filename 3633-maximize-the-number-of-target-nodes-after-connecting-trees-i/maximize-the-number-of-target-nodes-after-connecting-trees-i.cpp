
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> tree1 = buildGraph(edges1, n);
        vector<vector<int>> tree2 = buildGraph(edges2, m);

        // Compute maximum reachable nodes in tree2 within depth k - 1
        int maxReachableInTree2 = 0;
        if (k > 0) {
            for (int i = 0; i < m; ++i) {
                maxReachableInTree2 = max(maxReachableInTree2, dfs(tree2, i, -1, k - 1));
            }
        }

        // Compute result for each node in tree1
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = dfs(tree1, i, -1, k) + maxReachableInTree2;
        }

        return result;
    }

private:
    vector<vector<int>> buildGraph(const vector<vector<int>>& edges, int size) {
        vector<vector<int>> graph(size);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }

    int dfs(const vector<vector<int>>& graph, int node, int parent, int depth) {
        if (depth < 0) return 0;
        int count = 1;
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                count += dfs(graph, neighbor, node, depth - 1);
            }
        }
        return count;
    }
};
