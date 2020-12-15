class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string k=to_string(N);
        int n=k.size();
        int i=1;
        while(i<n&&k[i-1]<=k[i]) i++;
        if(i<n){
            while(i>0&&k[i-1]>k[i]){
                k[i-1]--;
                i--;
            }
            for(i++;i<n;i++){
                k[i]='9';
            }
        }
        return stoi(k);
    }
};