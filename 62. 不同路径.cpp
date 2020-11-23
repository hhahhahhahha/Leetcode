class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=m+n-2;
        if(x<=0) return 1;
        int c=min(m-1,n-1);
        long long  ans=1;
        for(int i=1;i<=c;i++){
            ans = ans * (x - c + i) / i;
        }
        return (int)ans;
    }
};