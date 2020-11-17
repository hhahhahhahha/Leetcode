class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex=0;
        for(int i=0;i<nums.size();i++){
            maxindex=max(maxindex,i+nums[i]);
            if(maxindex>=nums.size()-1) break;
            if(maxindex==i) return false;
        }
        return true;
    }
};