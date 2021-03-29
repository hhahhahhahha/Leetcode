class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int k=0;
        string left="";
        for(auto c:s){
            if(c==')'){
                if(k>0) {
                    k--;
                    left+=c;
                }
            }
            else if(c=='(') {
                k++;
                left+=c;
            }
            else left+=c;
        }
        cout<<left<<endl;
        string ans="";
        k=0;
        for(int i=left.size()-1;i>=0;i--){
             if(left[i]=='('){
                if(k>0){
                     k--;
                     ans+=left[i];
                }
            }
            else if(left[i]==')') {
                k++;
                ans+=left[i];
            }
            else ans+=left[i];
        }
        cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};