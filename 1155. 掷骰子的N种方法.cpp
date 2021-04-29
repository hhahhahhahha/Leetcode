class Solution {
public:
    int k[31][1001]={0};
    int numRollsToTarget(int d, int f, int target) {
        int mins=0;
        int maxs=0;
        k[0][0]=1;
        for(int i=1;i<=d;i++){
            for(int j=mins;j<=maxs;j++){
                for(int m=1;m<=f;m++){
                    if(j+m<=1000) {
                        k[i][j+m]+=k[i-1][j];
                        k[i][j+m]%=1000000007;
                    }
                }
            }
            mins++;
            maxs+=f;
            maxs=min(maxs,1000);
        }
        return k[d][target];
    }
};