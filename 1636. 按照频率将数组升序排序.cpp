class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> a;
        for(auto s:nums) a[s]++;//
        sort(nums.begin(),nums.end(),[&a](int x,int y){
            return (a[x]==a[y])? x>y:a[x]<a[y];
        });
        return nums;
    }
};
