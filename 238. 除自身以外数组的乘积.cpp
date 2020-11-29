class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> k(2,vector<int>(n,1));
        int begin=1;
        int begin2=1;
        for(int i=0;i<n-1;i++){
            begin*=nums[i];
            begin2*=nums[n-1-i];
            k[0][i+1]=begin;
            k[1][n-i-1-1]=begin2;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=k[0][i]*k[1][i];
        }
        return ans;
    }
};