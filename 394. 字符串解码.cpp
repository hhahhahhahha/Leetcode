class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;
        int nums=0;
        string  ks="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&& s[i]<='9') nums= nums*10+s[i] - '0';
            else if(s[i]=='[')
            {
                num.push(nums);
                nums=0;
                str.push(ks);
                ks="";
            }else if(s[i]==']')
            {
                for(int i=0;i<num.top();i++)
                    str.top()+=ks;
                ks=str.top();
                num.pop();
                str.pop();
            }else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z')) ks += s[i];
        }
        return ks;
    }
};
