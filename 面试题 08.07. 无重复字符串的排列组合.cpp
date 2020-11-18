class Solution {
private:
    vector<string> res;
    void dfs(string &s, int left){
        if(left==s.size()) res.emplace_back(s);
        for(int i=left; i<s.size(); ++i){
            swap(s[i], s[left]);
            dfs(s, left + 1);
            swap(s[i], s[left]);
        }
    }
public:
    vector<string> permutation(string S) {
        res.clear();
        dfs(S, 0);
        return res;
    }
};