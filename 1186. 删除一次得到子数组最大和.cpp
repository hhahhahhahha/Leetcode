class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        int ans=arr[0];
        int total=0;
        int total2=0;
        int minnum=0;
        for(int i=0;i<n;i++){
            total2+=minnum+arr[i];
            minnum=min(minnum,arr[i]);
            // total2=total-minnum;
            total+=arr[i];
            total2-=minnum;
            total2=max(total2,total-arr[i]);
            ans=max(ans,total);
            if(total2!=0) ans=max(ans,total2);
            if(total<0) total=0;
            // cout<<i<<" "<<total2<<" ";
            if(total2<=0){
                total2=0;
                minnum=0;
            }
            cout<<total<<" "<<total2<<" "<<minnum<<endl;
        } 
        return ans;
    }
};