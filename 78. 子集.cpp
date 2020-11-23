class Solution {
    vector<vector<int>> ans;
public:
    void suanfa(vector<int> m,int index,vector<int>& nums){
        if(index==nums.size()) return;
        suanfa(m,index+1,nums);
        m.push_back(nums[index]);
        ans.push_back(m);
        suanfa(m,index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> m;
        ans.push_back(m);
        suanfa(m,0,nums);
        return ans;
    }
};