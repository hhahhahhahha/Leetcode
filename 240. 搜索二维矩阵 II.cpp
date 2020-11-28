class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0) return false;
        int m=matrix[0].size();
        vector<int> last(m,n-1);
        for(int i=0;i<m;i++){
            if(matrix[0][i]>target) break;
            int first=0;
            int end=last[i];
            if(matrix[end][i]<target) continue;
            while(first<=end){
                int middle=(first+end)/2;
                if(matrix[middle][i]==target) return true;
                else if(matrix[middle][i]>target) {
                    end=middle-1;
                    if(i+1<m) last[i+1]=middle;
                }else {
                    first=middle+1;
                }
            }
        }
        return false;
    }
};