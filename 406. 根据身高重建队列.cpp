class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        int m=people.size();
        vector<vector<int>> ans(m);
        for(int i=0;i<m;i++){
            int empyt=0;
            for(auto& s:ans){
                if(s.empty()||s[0]==people[i][0]){
                    empyt++;
                    if(s.empty()&&empyt>people[i][1]) {
                        s=people[i];
                        break;
                    }
                } 
            }
        }
        return ans;
    }
};