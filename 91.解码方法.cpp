class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0||s[0]=='0') return 0; 
        else if(n==1) return 1;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<n;i++){
            if(s[i]<'7'&&s[i]>'0'&&s[i-1]=='2'||s[i-1]=='1'&&s[i]!='0') dp[i+1]=dp[i]+dp[i-1];
            else if(s[i]!='0') dp[i+1]=dp[i];
            else if(s[i-1]<'3'&&s[i-1]>'0') dp[i+1]=dp[i-1];
            else return 0;
        }
        return dp[n];   
    }
};
