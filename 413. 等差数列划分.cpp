class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int k=nums.size();
        if(k<=2) return 0;
        vector<int> dp(k,0);
        int dengcha=nums[1]-nums[0];
        int number=1;
        // cout<<dengcha<<endl;
        for(int i=2;i<k;i++){
            if(nums[i]-nums[i-1]==dengcha) {
                dp[i]=dp[i-1]+number;
                 number+=1;
                //  cout<<number<<endl;
            }
            else {
                dengcha=nums[i]-nums[i-1];
                dp[i]=dp[i-1];
                number=1;
            }
        }
        return dp[k-1];
    }
};