class Solution {
public:
    long long minimumCost(
        string source,
        string target,
        vector<string>& original,
        vector<string>& changed,
        vector<int>& cost
    ) {
        const long long INF = 1e18;
        int n = source.size();
        int m = original.size();

        // Collect all unique strings
        unordered_map<string, int> id;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            if (!id.count(original[i])) id[original[i]] = idx++;
            if (!id.count(changed[i]))  id[changed[i]]  = idx++;
        }

        int K = idx;
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < K; i++) dist[i][i] = 0;

        // Build graph
        for (int i = 0; i < m; i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < K; k++)
            for (int i = 0; i < K; i++)
                for (int j = 0; j < K; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        // Group rule strings by length
        unordered_map<int, vector<string>> byLen;
        for (auto &p : id)
            byLen[p.first.size()].push_back(p.first);

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            // Single character
            if (source[i] == target[i])
                dp[i + 1] = min(dp[i + 1], dp[i]);

            // Substring transitions
            for (auto &[L, vec] : byLen) {
                if (i + L > n) continue;

                string sSub = source.substr(i, L);
                string tSub = target.substr(i, L);

                if (!id.count(sSub) || !id.count(tSub)) continue;

                int u = id[sSub];
                int v = id[tSub];

                if (dist[u][v] < INF) {
                    dp[i + L] = min(dp[i + L], dp[i] + dist[u][v]);
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
