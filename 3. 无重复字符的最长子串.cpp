class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = s.size();
        if (m == 0) return 0;
        vector<int> dp(m, m);//保存当前小标对应字符的下一个下标例如对应abcdc ，dp[2](2表示的是s中下标为2的字符c)保存的是下一个字符c的下标也就是4，如果没有相同的字符，则保存的是字符串长度。例如刚才的字符串dp[1]保存5(字符b之后没有字符b))
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (s[i] == s[j]) {
                    dp[i] = j;
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++) {//例如abcdmnna,对于第一个字符a，dp[1]保存的是第二个a的下标也就是7。但是0和7之间有两个相同的字符串n,所以跟新dp[1]为第二个n的下标
            for (int j = i + 1; j < dp[i]; j++) {
                if (dp[j] < dp[i]) {
                    dp[i] = dp[j];
                }
            }
        }
        int imax = 1;
        for (int i = 0; i < m; i++) {
             imax = max(imax, dp[i] - i);
        }
        return imax;
    }
};