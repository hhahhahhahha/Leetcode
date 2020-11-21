class Solution {
private:
    vector<string> ans;
public:
    void suanfa(vector<int> dp,string m,int d){
        if(m.size()==d) {
            ans.push_back(m);
            return;
        }
        if(dp[0]>0){
            dp[0]--;
            suanfa(dp, m+"(",d);
            dp[0]++;
        }
        if(dp[1]>0&&dp[0]<dp[1]){
            dp[1]--;
            suanfa(dp,m+")",d);
            dp[1]++;
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n==0) return ans;
        vector<int> dp(2,n);
        string m="";
        suanfa(dp,m,2*n);
        return ans;
    }
};