class Solution {
public:
    int ans=0;
    void suanfa(TreeNode* root,int number,int sum,bool ks){
        if(root==NULL) return;
        if(ks) {
            suanfa( root->left, number,sum,ks);
            suanfa( root->right, number,sum,ks);
        }
        number+=root->val;
        if(number==sum) ans++;
        suanfa( root->left, number,sum,false);
        suanfa( root->right, number,sum,false);
    }
    int pathSum(TreeNode* root, int sum) {
        suanfa(root,0,sum,true);
        return ans;
    }
};