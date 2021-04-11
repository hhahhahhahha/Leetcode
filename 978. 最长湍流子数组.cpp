class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n<=2){
            if(n==2&&arr[0]!=arr[1]) return 2;
            else return 1;
        }
        int ans=1;
        int temlength=1;
        for(int i=1;i<n-1;i++){
            if((arr[i]>arr[i-1]&&arr[i]>arr[i+1])||(arr[i]<arr[i-1]&&arr[i]<arr[i+1])){
                temlength++;
            }else{
                if(arr[i-1]==arr[i]&&arr[i]==arr[i+1]) ans=max(ans,temlength);
                else ans=max(ans,temlength+1);
                temlength=1;
            }
        }
        if(arr[n-3]==arr[n-2]&&arr[n-2]==arr[n-1]) ans=max(ans,temlength);
        else ans=max(ans,temlength+1);
        return ans;
    }
};