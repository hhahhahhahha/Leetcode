class Solution {
public:
    int numSub(string s) {
        int ans=0;
        int length=0;
        for(auto i:s){
            if(i=='1'){
                length++;
                ans=(ans+length)%1000000007;
            }
            else length=0;
        }
        return ans;
    }
};