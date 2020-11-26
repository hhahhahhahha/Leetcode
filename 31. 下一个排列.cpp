class Solution {
public
    void nextPermutation(vectorint& nums) {
        int n=nums.size();
        if(n=1) return;
        int x=0;
        for(int i=1;in;i++){
            if(nums[i]nums[i-1]) x=i;
        }
        if(x==0) sort(nums.begin(),nums.end());
        else if(x==n-1) swap(nums[n-2],nums[n-1]);
        else {
            for(int i=x;in;i++){
                if(nums[i]=nums[x-1]) {
                    swap(nums[i-1],nums[x-1]);
                    break;
                }
                if(i==n-1) swap(nums[n-1],nums[x-1]);
            }
            sort(nums.begin()+x,nums.end()); 
        }
    }
};