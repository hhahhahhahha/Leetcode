class Solution {
public:
    //21.3.2 Tuesday
    double largestSumOfAverages(vector<int>& A, int K) {
        /*
            状态：数组A的每个元素，分割为K个相邻的数组
            选择：枚举所有分割k的可能性，分割成k份 == 分割成k-1份+最后一份
        */

        vector<double> sum(A.size()+1,0.0);
        vector<vector<double>> dp(A.size()+1,vector<double>(K+1,0));

        for(int i =1;i<=A.size();++i){
            sum[i] = sum[i-1]+A[i-1];
        }
        for(int i =1;i<=A.size();++i){
            dp[i][1] = sum[i] / i;
            for(int k=2;k<=K && k<=i;++k){
                for(int j = 1;j<i;++j){
                    dp[i][k] = max( dp[i][k],dp[j][k-1] + (sum[i]-sum[j])/(i-j));
                }
            }
        }
        return dp[A.size()][K];
    }
};