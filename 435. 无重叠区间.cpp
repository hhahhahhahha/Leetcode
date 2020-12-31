class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int length=intervals.size();
        int k=0;
        for(int i=1;i<length;i++){
            if(intervals[k][1]>intervals[i][0]) {
                if(intervals[k][1]>intervals[i][1]) k=i;
                ans++;
            }else k=i;
        }
        return ans;
    }
};