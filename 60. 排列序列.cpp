class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> dx={1,1,2,6,24,120,720,5040,40320};
        vector nums(n+1,0);
        string ret;
        k--;
        iota(begin(nums),end(nums),0);
        for(int i=n-1;i>=0;i--){
            auto it=nums.begin()+k/dx[i]+1;
            ret +=('0'+*it);
            nums.erase(it);
            k%=dx[i];
        }
        return ret;
    }
};