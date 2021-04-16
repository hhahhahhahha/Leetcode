class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long LL;

    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<LL> > dp(n+1, vector<LL>(7));
        // 初始化
        for (int j = 1; j <= 6; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                // 加入第 i-1 次得所有可能序列总数
                LL ans = accumulate(dp[i-1].begin(), dp[i-1].end(), 0LL);
                int idx = i - 1 - rollMax[j-1];
                if (idx >= 1) {
                    // 减去 i - 1 - rollMax[j-1]次掷出1，2，3，4，5 的所有序列总数
                    ans = accumulate(dp[idx].begin(), dp[idx].end(), ans, [&](LL init, LL e) {
                        return init + MOD - e;
                    });
                    ans += dp[idx][j];
                }else if (idx == 0) {
                    // 特殊情况处理
                    ans -= 1;
                }
                dp[i][j] = ans % MOD;
            }
        }
        return accumulate(dp[n].begin(), dp[n].end(), 0LL) % MOD;
    }
};
