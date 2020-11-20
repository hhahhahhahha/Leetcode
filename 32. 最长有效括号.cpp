class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n<=1) return 0;
        stack<int> xm;
        vector<int> dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') xm.push(i);
            else if(!xm.empty()){
                if(i!=0&&xm.top()!=0) dp[i]=dp[i-1]+2+dp[xm.top()-1];
                else if(xm.top()==0) dp[i]=dp[i-1]+2;
                xm.pop();
                ans =max(ans,dp[i]);
            }
        }
        return ans;
    }
};