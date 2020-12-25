class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> k;
        vector<vector<string>> ans;
        for(auto s:strs){
            string copy=s;
            sort(copy.begin(),copy.end());
            if(k.count(copy)){
                ans[k[copy]].push_back(s);
            }else{
                k[copy]=ans.size();
                ans.push_back({s});
            }
        }
        return ans;
    }
};