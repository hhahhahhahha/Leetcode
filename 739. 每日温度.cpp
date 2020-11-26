class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> ans(n,0);
        stack<int> dp;
        for(int i=0;i<n;i++){
            while(!dp.empty()&&T[dp.top()]<T[i]){
                int n=dp.top();
                ans[n]=i-n;
                dp.pop();
            }
            dp.push(i);
        }
        return ans;
    }
};