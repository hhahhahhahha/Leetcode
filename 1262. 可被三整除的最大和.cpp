class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int m[3]={0,0,0};
        for(auto s:nums){
            int tem[3]={m[0],m[1],m[2]};
            for(int i=0;i<=2;i++){
                m[(tem[i]+s)%3]=max(m[(tem[i]+s)%3],tem[i]+s);
            }
            // cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<endl;
        }
        return m[0];
    }
};