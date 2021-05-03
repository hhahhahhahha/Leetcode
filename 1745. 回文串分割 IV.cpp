class Solution {
public:
    bool checkPartitioning(string s) {
        int lenth=s.size();
        vector<vector<bool>> dp(lenth,vector<bool>(lenth,true));
        for(int i=1;i<lenth;i++){
            for(int j=0;i+j<lenth;j++){
                dp[j][i+j]=dp[j+1][i+j-1]&&s[j]==s[i+j];
            }
        }
        for(int i=0;i<lenth;i++){
            if(dp[0][i]){
                for(int j=i+1;j<lenth;j++){
                    if(dp[i+1][j]){
                        if(j+1<lenth&&dp[j+1][lenth-1]) return true;
                    }
                }
            }
        }
        return false;
   }
};