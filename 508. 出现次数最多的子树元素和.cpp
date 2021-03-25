class Solution {
public:
    unordered_map<int,int> dp;
    int suanfa(TreeNode* root){
        if(root==NULL) return 0;
        int ans=suanfa(root->left)+root->val+suanfa(root->right);
        dp[ans]++;
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        suanfa(root);
        vector<int> ans;
        int index=1;
        for(auto s:dp){
            if(s.second>index){
                ans.clear();
                index=s.second;
                ans.push_back(s.first);
            }else if(index==s.second){
                ans.push_back(s.first);
            }
        }
        return ans;
    }
};