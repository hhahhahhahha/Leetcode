class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> hang(10,vector<bool>(10,false));
        vector<vector<bool>> lie(10,vector<bool>(10,false));
        vector<vector<vector<bool>>> square(4,vector<vector<bool>>(4,vector<bool>(10,false)));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(hang[i][board[i][j]-'0']==true) return false;
                else hang[i][board[i][j]-'0']=true;
                if(lie[j][board[i][j]-'0']==true) return false;
                else lie[j][board[i][j]-'0']=true;
                if(square[i/3][j/3][board[i][j]-'0']==true) return false;
                else square[i/3][j/3][board[i][j]-'0']=true;
            }
        }
        return true;
    }
};