class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> maxlen;
        //maxlen.push_back({nums[0],0});
        vector<int> anser;
        for(int i=0;i<nums.size();i++){
            while(!maxlen.empty()&&maxlen.back().first<nums[i]) maxlen.pop_back();
            maxlen.push_back({nums[i],i});
            while(!maxlen.empty()&&maxlen.front().second<=i-k) maxlen.pop_front();
            if(i>=k-1) anser.push_back(maxlen.front().first);
        }
        return anser;
    }
};
