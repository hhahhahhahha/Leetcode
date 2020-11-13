class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5,vector<int>(n+1,0));
        for(auto& s:dp){
            s[1]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<5;j++){
                for(int m=0;m<=j;m++) dp[j][i]+=dp[m][i-1];
            }
        }
        int max=0;
        for(int c=0;c<5;c++) max+=dp[c][n];
        return max;
    }
};