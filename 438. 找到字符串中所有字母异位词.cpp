class Solution {
public:
    unordered_map<char,int> smap;
    unordered_map<char,int> pmap;
    bool check(){
        for(const auto &s:pmap){
            if(smap[s.first]<s.second) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int end=p.size()-1;
        int first=0;
        vector<int> ans;
        for(auto s:p){
            pmap[s]++;
        }
        for(int i=first;i<=end;i++){
            smap[s[i]]++;
        }
        for(;end<s.size();){
            if(check()) ans.push_back(first);
            smap[s[first]]--;
            first++;
            end++;
            smap[s[end]]++;
        }
        return ans;
    }
};