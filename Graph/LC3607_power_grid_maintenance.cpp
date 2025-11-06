class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n+1);
            size.assign(n+1, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int u) {
            return parent[u] == u ? u : parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {
            u = find(u);
            v = find(v);
            if (u == v) return;
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Build connections
        for (auto &edge : connections)
            dsu.unite(edge[0], edge[1]);

        // Group by component
        unordered_map<int, vector<int>> component;
        for (int i = 1; i <= c; ++i)
            component[dsu.find(i)].push_back(i);

        // Maintain online nodes per component
        unordered_map<int, set<int>> onlineStations;
        for (auto &[root, nodes] : component)
            onlineStations[root] = set<int>(nodes.begin(), nodes.end());

        vector<bool> isOnline(c+1, true);
        vector<int> ans;

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);

            if (type == 1) { // maintenance check
                if (isOnline[x]) {
                    ans.push_back(x);
                } else if (!onlineStations[root].empty()) {
                    ans.push_back(*onlineStations[root].begin());
                } else {
                    ans.push_back(-1);
                }
            } else if (type == 2) { // go offline
                if (isOnline[x]) {
                    isOnline[x] = false;
                    onlineStations[root].erase(x);
                }
            }
        }

        return ans;
    }
};