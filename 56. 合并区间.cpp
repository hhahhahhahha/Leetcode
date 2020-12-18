class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int m=intervals.size();
        if(m<=0) return ans;
        for(int i=0;i<m;i++){
            if(ans.empty()) ans.push_back(intervals[i]);
            else if(ans.back()[1]<intervals[i][0]) ans.push_back(intervals[i]);
            else if(ans.back()[1]<intervals[i][1]) ans.back()[1]=intervals[i][1];
        }
        return ans;
    }
};