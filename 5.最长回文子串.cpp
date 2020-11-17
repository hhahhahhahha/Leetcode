class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return s;
        vector<vector<int>> f(n,vector<int>(n));
        string  ans="";
        for(int i=0;i<=n-1;i++){
            for(int j=0;j+i<n;j++){
                int m=i+j;
                if(i==0) f[j][m]=1;
                else if(i==1) f[j][m]=s[j]==s[m];
                else f[j][m]=f[j+1][m-1]&&s[j]==s[m];
                if(f[j][m]&&i+1>ans.size()) ans=s.substr(j,i+1);
            }
        }
        return ans;
    }
};