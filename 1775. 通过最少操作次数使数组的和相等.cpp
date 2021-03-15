public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) {
            return 0;
        }
        if (sum1 > sum2) {
            return minOperations(nums2, nums1);
        }

        int diff = sum2 - sum1;
        vector<int> freq(6);
        for (int num: nums1) {
            ++freq[6 - num];
        }
        for (int num: nums2) {
            ++freq[num - 1];
        }
        int ans=0;
        for(int i=5;i>=1&&diff>0;--i){
            while(freq[i]&&diff>0){
                ans++;
                freq[i]--;
                diff-=i;
            }
        }
        return diff > 0? -1:ans;
    }
};