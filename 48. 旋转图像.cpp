class Solution {
public:
    void jiaohuan(int &a,int &b){
        int c=a;
        a=b;
        b=c;
    }
    void rotate(vector<vector<int>>& matrix) {
        int lenth=matrix.size();
        for(int i=0;i<lenth;i++){
            for(int j=0;j<i;j++){
                jiaohuan(matrix[i][j],matrix[j][i]);
            }
        }
        int middle=lenth/2;
        for(int i=0;i<lenth;i++){
            for(int j=0;j<middle;j++){
                jiaohuan(matrix[i][j],matrix[i][lenth-j-1]);
            }
        }
    }
};