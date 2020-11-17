class Solution {
public:
    void dfs(vector<int>& candidates,vector<int>& combines,int target,int index,vector<vector<int>>& ans){
        if(index==candidates.size()||target<0) return;
        if(target==0) {
            ans.emplace_back(combines);
            return;
        }
        dfs(candidates,combines,target,index+1,ans);
        combines.emplace_back(candidates[index]);
        dfs(candidates,combines,target-candidates[index],index,ans);
        combines.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combines;
        vector<vector<int>> ans;
        dfs(candidates,combines,target,0,ans);
        return ans;
    }
};