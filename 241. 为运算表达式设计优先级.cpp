class Solution {
public:
    vector<int> part(string& expression,int start,int end){
        vector<int> ans;
        // cout<<start<<end<<"下标"<<endl;
        for(int i=start;i<=end;i++){
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
                vector<int> pre=part(expression,start,i-1);
                vector<int> pres=part(expression,i+1,end);
                for(auto m:pre){
                    for(auto n:pres){
                        if(expression[i]=='+') ans.push_back(m+n);
                        else if(expression[i]=='-') ans.push_back(m-n);
                        else if(expression[i]=='*') ans.push_back(m*n);
                    }
                }
            }
        }

        if(ans.empty()) {
            string kk=expression.substr(start,end-start+1);
            ans.push_back(stoi(kk));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return part(expression,0,expression.size()-1);
    }
};