class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = to_string(n);
        int len = numStr.size();
        stack<int> monotoneStack;
        int memIdx = -1;
        long res = -1;
        for (int i = len - 1; i >= 0; i--) {
            while (!monotoneStack.empty() && numStr[monotoneStack.top()] > numStr[i]) {
                memIdx = monotoneStack.top();
                monotoneStack.pop();
            }
            if (memIdx != -1) {
                swap(numStr[i], numStr[memIdx]);
                int left = i + 1, right = len - 1;
                while (left < right) {
                    swap(numStr[left], numStr[right]);
                    left++;
                    right--;
                }
                res = atol(numStr.c_str());
                if (res > INT_MAX) return -1;
                else return int(res);
            }
            monotoneStack.push(i);
        }
        return -1;
    }
};