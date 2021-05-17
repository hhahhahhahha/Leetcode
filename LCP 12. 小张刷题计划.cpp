class Solution {
public:
    bool suanfa(vector<int>& time,int m ,int maxs){
        int j=0;
        int total=0;
        int maxi=0;
        for(int i=0;i<m;i++){
            total=0;
            maxi=time[j];
            while(true){
                j++;
                if(j>=time.size()) break;
                total+=maxi+time[j];
                maxi=max(maxi,time[j]);
                total-=maxi;
                if(total>maxs){
                    break;
                }
            }
            if(j>=time.size()) break;
        }
        if(j>=time.size()) return true;
        else return false;//false表示max太小了，true表示j太大了。
    }
    int minTime(vector<int>& time, int m) {
        if(time.size()<=m) return 0;
        int total=0;
        for(auto s:time){
            total+=s;   
        }
        int first=0;
        int end=total;
        while(first<end){
            int middle=(first+end)/2;
            if(suanfa(time,m,middle)){
                end=middle;
            }else{
                first=middle+1;
            }
        }
        return first;
    }
};