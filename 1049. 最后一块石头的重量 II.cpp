class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum >> 1;
        
        int d[target+1];
        memset(d, 0, sizeof(int)*(target+1));

        for (int i = 0; i < n; ++i)
        {
            int currWeight = stones[i];
            for (int j = target; j >= currWeight; --j)
            {
                d[j] = max(d[j], d[j-currWeight] + currWeight);
            }
        }

        return sum - (d[target] << 1);
    }
};