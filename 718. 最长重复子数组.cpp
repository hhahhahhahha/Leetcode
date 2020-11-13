class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int LenA=A.size();
        int LenB=B.size();
        if(LenA==0||LenB==0) return 0;
        vector<vector<int>> dp(LenA,vector<int>(LenB,0));
        int lenmax=0;
        for(int i=0;i<LenA;i++){
            for(int j=0;j<LenB;j++){
                if(B[j]==A[i]){
                    if(i==0||j==0){
                        dp[i][j]=1;
                    }
                    else dp[i][j]=dp[i-1][j-1]+1;
                }
                lenmax=max(lenmax,dp[i][j]);
            }
        }
        return lenmax;
    }
};