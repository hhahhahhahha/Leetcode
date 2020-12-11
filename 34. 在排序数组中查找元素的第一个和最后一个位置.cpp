class Solution {
public:
    int suanfa(vector<int> &nums,int target,bool low){
        int left=0;
        int right=nums.size()-1;
        int ans=right+1;
        while(left<=right){
            int middle=(left+right)/2;
            if(nums[middle]>target||(low&&nums[middle]>=target)){
                right=middle-1;
                ans=middle;
            }else{
                left=middle+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=suanfa(nums,target,true);
        int right=suanfa(nums,target,false)-1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target) {
            return vector<int>{left, right};
        } 
        return vector<int>{-1,-1};
    }
};