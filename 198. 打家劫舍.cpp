class Solution {
public:
    int rob(vector<int>& nums) {
        int length=nums.size();
        int mix=0;//偷
        int mixs=0;//不偷
        int mixs2=0;//连续不偷
        for(int i=0;i<length;i++){
            int c=mixs;//连续两次不偷
            int b=mix;//不偷
            int a=max(mixs+nums[i],mixs2+nums[i]);//偷
            mix=a;
            mixs=b;
            mixs2=c;
        }
        return max(mix,max(mixs,mixs2));
    }
};