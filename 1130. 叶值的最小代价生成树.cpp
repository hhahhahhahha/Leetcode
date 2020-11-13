class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{INT_MAX,0}));
        for(int i=0;i<n;i++){
            dp[i][i]={0,arr[i]};
        }
        for(int len=1;len<n;len++){
            for(int i=0,j;i+len<n;i++){
                j=i+len;
                for(int k=i;k<j;k++){
                    if(dp[i][j].first>dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second){
                        dp[i][j].first=dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second;
                        dp[i][j].second=max(dp[i][k].second,dp[k+1][j].second);
                    }
                }
            }
        }
        return dp[0][n-1].first;
    }
};