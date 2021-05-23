class Solution {
public:
    // int suanfa(string& word1, string& word2,int index1, int index2){
    //     if(index1>=word1.size()) return word2.size()-index2;
    //     if(index2>=word2.size()) return word1.size()-index1;
    //     if(word1[index1]==word2[index2]){
    //         return suanfa(word1,word2,index1+1,index2+1);
    //     }else{
    //         return min(suanfa(word1,word2,index1+1,index2),suanfa(word1,word2,index1,index2+1))+1;
    //     }
    // }
    int minDistance(string word1, string word2) {
        int index1=word1.size();
        int index2=word2.size();
        vector<vector<int>> dp(index1+1,vector<int>(index2+1,0));
        for(int i=0;i<=index2;i++)dp[0][i]=i;
        for(int j=0;j<=index1;j++) dp[j][0]=j;
        for(int i=1;i<=index1;i++){
            for(int j=1;j<=index2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            }
        }
        return dp[index1][index2];
    }
};