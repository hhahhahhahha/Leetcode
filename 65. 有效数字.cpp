class Solution {
public:
    bool isInteger(string n){
        if(n==""||n=="+"||n=="-") return false;
        int i=(n[0]=='+'||n[0]=='-')? 1:0;
        for(;i<n.size();i++){
            if(n[i]<'0'||n[i]>'9') return false;
        }
        return true;
    }
    bool isdecimalOrInteger(string n){
        if(isInteger(n)) return true;
        if(n==""||n=="+"||n=="-") return false;
        int i=(n[0]=='+'||n[0]=='-')? 1:0;
        bool m=true;
        for(;i<n.size();i++){
            if(n[i]=='.') {
                if(!m) return false;
                m=false;
                if(i==0){
                    //cout<<n[i]<<n[i+1];
                    if(n.size()==1) return false;
                    if((n[i+1]<'0'||n[i+1]>'9')) return false;
                }else if(i==n.size()-1){
                    if((n[i-1]<'0'||n[i-1]>'9'))return false;
                }else{
                    if(((n[i-1]<'0'||n[i-1]>'9')&&(n[i+1]<'0'||n[i+1]>'9')))return false;
                }
                //cout<<n[i]; 
            }
            else if(n[i]<'0'||n[i]>'9') return false;
            //cout<<n[i]; 
        }
        return true;
    }
    bool isNumber(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='e'||s[i]=='E') return isdecimalOrInteger(s.substr(0,i))&&isInteger(s.substr(i+1,s.size()-i-1));
        }
        return isdecimalOrInteger(s);
    }
};