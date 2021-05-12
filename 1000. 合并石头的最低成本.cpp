class Solution {
public
    int mergeStones(vectorint& stones, int K) {
        int n = stones.size(), sum[n + 1];
        if((n-1) % (K - 1) != 0) return -1;
        sum[0] = 0;
        for(int i=1;i=n;i++) sum[i] = sum[i-1] + stones[i-1];
        int f[n + 1][n + 1][K + 1];
        memset(f,0x3f3f3f3f,sizeof f);
        for(int i=1;i=n;i++) f[i][i][1] = 0;

        for(int len=2;len=n;len++) {
            for(int i=1;i+len-1=n;i++) {
                int j = i + len - 1;
                for(int p=i;pj;p++) {
                    for(int k=2;k=K;k++) {
                        f[i][j][k] = min(f[i][j][k], f[i][p][1] + f[p+1][j][k-1]);
                    }
                }
                f[i][j][1] = f[i][j][K] + sum[j] - sum[i - 1];
            }
        }
        return f[1][n][1];
    }
};