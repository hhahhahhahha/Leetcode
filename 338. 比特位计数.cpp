class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> anser(num+1,0);
        for(int i=0;i<=num;i++){
            int m=1;
            while(m<=i){
                if(i&m) anser[i]++;
                m=m<<1;
            }
        }
        return anser;
    }
};