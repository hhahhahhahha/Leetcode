class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n, n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m<=0) return 0;
        int n=matrix[0].size();
        vector<int> dp(n,0);
        int maxans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') dp[j]++;
                else dp[j]=0;
            }
            int ans=largestRectangleArea(dp);
            maxans=max(maxans,ans);
        }
        return maxans;
    } 
};