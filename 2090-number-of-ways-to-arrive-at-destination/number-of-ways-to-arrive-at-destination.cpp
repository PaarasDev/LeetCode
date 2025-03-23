class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (time > dist[node]) continue;
            
            for (auto [next, t] : graph[node]) {
                long long newDist = time + t;
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    ways[next] = ways[node];
                    pq.emplace(newDist, next);
                } else if (newDist == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};