class Solution {
public:
    int m=0,n=0,ans=0;
    bool check(int x,int y){
        return x>0&&y>0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    //ans+=min();
                    if(check(i,j)) dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                    else dp[i][j]=1;
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};