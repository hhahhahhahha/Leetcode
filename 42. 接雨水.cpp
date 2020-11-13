class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int maxtrap=0;
        for(int i=0;i<height.size();i++){
            while(!st.empty()&&height[st.top()]<height[i]){
                int top=st.top();
                st.pop();
                if(st.empty()) break;
                maxtrap+=(min(height[i],height[st.top()])-height[top])*(i-st.top()-1);
            }
            st.push(i);
        }
        return maxtrap;
    }
};