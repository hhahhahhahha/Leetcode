class Solution {
private:
    int ans=0;
public:
    void suanfa(int index,int target,vector<int>& nums ){
        if(index==nums.size()) return;
        suanfa(index+1,target,nums);
        if(target-nums[index]>=0) suanfa(index+1,target-nums[index],nums);
        if(target-nums[index]==0) ans++;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int num=0;
        int m=0;
        for(int i=0;i<nums.size();i++){
            num+=nums[i];
            if(nums[i]==0) m++;
        }
        int target=0;
        if((num-S)%2==0){
            target=(num-S)/2;
        }else return 0;
        if(target==0) return pow(2,m);
        suanfa(0,target,nums);
        return ans;
    }
};