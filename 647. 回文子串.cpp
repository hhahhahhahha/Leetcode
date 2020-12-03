class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j+i<n&&i-j>=0;j++){
                if(s[i-j]==s[i+j]) ans++;
                else break;
            }
            for(int j=0;j+i+1<n&&i-j>=0;j++){
                if(s[i-j]==s[i+j+1]) ans++;
                else break;
            }
        }
        return ans;
    }
};