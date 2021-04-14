class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int k=i;//获取位置
            for(int j=0;j<m;j++){
                if(k+1<n&&grid[j][k]==1&&grid[j][k+1]==1){
                    k++;
                }else if(k-1>=0&&grid[j][k]==-1&&grid[j][k-1]==-1){
                    k--;
                }else {
                    ans.push_back(-1);
                    break;
                }
                if(j==m-1) ans.push_back(k);
            }
        }
        return ans;
    }
};