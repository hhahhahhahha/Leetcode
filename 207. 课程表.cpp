class Solution {
private:
    vector<vector<int>> data;
    vector<int> visited;
    bool ans=true;
public:
    void suanfa(int i){
        visited[i]=1;
        for(const auto& s:data[i]){
            if (visited[s] == 0) {
                suanfa(s);
                if (!ans) {
                    return;
                }
            }
            else if (visited[s] == 1) {
                ans = false;
                return;
            }
        }
        visited[i]=2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        data.resize(numCourses);
        for(const auto& s:prerequisites){
            data[s[1]].push_back(s[0]);
        }
        for(int i=0;i<numCourses&&ans;i++){
            if(!visited[i]) suanfa(i);
        }
        return ans;
    }
};