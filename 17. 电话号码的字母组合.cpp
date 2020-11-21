class Solution {
private:
    vector<string> letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
public:
    void sunaf(string m,int index,int n,string& digits){
        if(index==n) {
            ans.push_back(m);
            return ;
        }
        for(auto s:letters[digits[index]-'0']){
            sunaf(m+s,index+1,n,digits);
        } 
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return ans;
        string m;
        sunaf(m,0,n,digits);
        return ans;
    }
};