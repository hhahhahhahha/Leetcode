class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        if(ladders>=n-1) return n-1;
        vector<int> needbricks(n,0);//needbricks[0]不使用
        for(int i=1;i<n;i++) {
            if(heights[i]>heights[i-1]) needbricks[i]=heights[i]-heights[i-1];
        }
        int restbricks=bricks;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=1;i<n;i++){
            if(needbricks[i]>0){
                q.push(needbricks[i]);
                if (q.size() > ladders) {
                    restbricks -= q.top();
                    q.pop();
                }
                if(restbricks<0) return i-1;
            }
        }
        return n-1;
    }
};