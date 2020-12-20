class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> key;
        int len=tasks.size();
        int ans=0;
        int maxtasks=0;
        int res=0;
        for(auto s:tasks){
            key[s]++;
            maxtasks=max(maxtasks,key[s]);
        }
        for(auto s:key){
            if(maxtasks==s.second) res++;
        }
        ans=max((maxtasks-1)*(n+1)+res,len);
        return ans;
    }
};