class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = static_cast<int>(stamp.size()), n = static_cast<int>(target.size());
        vector<int> inDegree(n - m + 1, m);
        vector<vector<int>> edges(n);
        vector<bool> seen(n);
        vector<int> q;
        for (int i = 0; i < n - m + 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target[i + j] == stamp[j]) {
                    inDegree[i] -= 1;
                    if (inDegree[i] == 0) q.emplace_back(i);
                } else {
                    edges[i + j].emplace_back(i);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int cur = q.back();
            q.pop_back();
            ans.emplace_back(cur);
            for (int i = 0; i < m; i++) {
                if (!seen[cur + i]) {
                    seen[cur + i] = true;
                    for (auto &&edge : edges[cur + i]) {
                        inDegree[edge] -= 1;
                        if (inDegree[edge] == 0) q.emplace_back(edge);
                    }
                }
            }
        }
        if (static_cast<int>(ans.size()) < n - m + 1) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};