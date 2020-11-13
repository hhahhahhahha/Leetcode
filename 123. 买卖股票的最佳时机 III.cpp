class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<int> firstd(n,0),secondd(n,0);//
        int maxfirst=0;
        int maxsecond=0;
        pair<int,int> minmaxprince={prices.front(),prices.back()};
        for(int i=0;i<n;i++){
            if(prices[i]<=minmaxprince.first) minmaxprince.first=prices[i];
            else maxfirst=max(maxfirst,prices[i]-minmaxprince.first);
            firstd[i]=maxfirst;
            if(prices[n-1-i]>=minmaxprince.second) minmaxprince.second=prices[n-1-i];
            else maxsecond=max(maxsecond,minmaxprince.second-prices[n-1-i]);
            secondd[n-1-i]=maxsecond;
        }
        int anser=0;
        for(int i=0;i<n;i++){
            anser=max(anser,firstd[i]+secondd[i]);
        }
        return anser;
    }
};