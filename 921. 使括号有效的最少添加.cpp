class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans=0;
        int pre=0;
        for(auto i:S){
            if(i=='(') pre++;
            else {
                if(pre>0) --pre;
                else ans++;
            }
        }
        ans+=pre;
        return ans;
    }
};