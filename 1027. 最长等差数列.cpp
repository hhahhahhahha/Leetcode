class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if (n <= 2)
        {
            return n;
        }
        int d[n][n];
        for (int i = 0; i < n; ++i)
        {
            // 严格意思上看其实应该是2，但是为了简单，直接用了0，最后结果时候加上就可以
            memset(d[i], 0, sizeof(int) * n);
        }

        // unordered_map<int, int> num2index;
        int num2index[10001];
        memset(num2index, 1, sizeof(int)*10001);

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // 当前差值 A[i]-A[j] = exp-A[i] -> exp = A[i]*2 -A[j] 
                int exp = (A[i] << 1) - A[j];
                if (num2index[exp+5000] < 10000)
                {
                    // 加上新的j元素，所以是+1
                    d[i][j] = d[num2index[exp+5000]][i] + 1;
                }
                res = max(res, d[i][j]);
            }
            num2index[A[i]+5000] = i;
        }

        // 需要额外+2，因为初始值我们都是0
        return res + 2;
    }
};

