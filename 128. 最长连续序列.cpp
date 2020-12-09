class Solution {
public:
    unordered_map<int,int> a;
    int find(int x){
            return a.count(x)?a[x]=find(a[x]):x;
        }
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        for(int i:nums){
            a[i]=i+1;
        }
        for(auto i:nums){
            int d=find(i+1);
            ans=max(ans,d-i);
        }
        return ans;
    }
};