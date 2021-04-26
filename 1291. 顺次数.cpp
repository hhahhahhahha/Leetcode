class Solution {
public:
    vector<int> ans;
    void suanfa(int i,int low,int high){
        if(i>high) return;
        int tem=i%10;
        if(tem>=9) return;
        i=i*10+tem+1;
        if(i>=low&&i<=high) ans.push_back(i);
        suanfa(i,low,high);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++){
            suanfa(i,low,high);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};