class Solution {
public:
    int numPermsDISequence(string S) {
        int i, j, size = S.size(), sum = 0, mod = 1000000007;
        vector<vector<int>> dp(size + 1, vector<int>(size + 1));  // 令dp[i][j]表示字符串长度为i时，以j为结尾的序列个数
        dp[0][0] = 1;  // 序列0

        for (i = 1; i <= size; ++i) {
            if (S[i - 1] == 'D') {
                dp[i][i] = 0;  // 最后一个数是i，肯定不可能构成降序
                for (j = i - 1; j >= 0; --j) {
                    dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;  // 最后一个数是j，那么上一个序列中所有大于等于j结尾的序列都可以构成降序
                }
            }
            else {
                dp[i][0] = 0;  // 最后一个数是0，肯定不可能构成升序
                for (j = 1; j <= i; ++j) {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;  // 最后一个数是j，那么上一个序列中所有小于j结尾的序列都可以构成升序
                }
            }
        }

        for (j = 0; j <= size; ++j) {
            sum = (sum + dp[size][j]) % mod;
        }

        return sum;
    }
};