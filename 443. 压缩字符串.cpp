class Solution {
public:
    int compress(vector<char>& s) {
        int n = s.size(), index = 0;
        for(int i = 0, j = 0; i < n; i = j)
        {
            j = i + 1;
            while(j < n && s[j] == s[i])    ++j;    //移动j到直至s[j]不等于s[i]
            s[index++] = s[i];                      //加入待处理字符s[i]
            if(j - i == 1)  continue;               //该字符大小为1时,直接统计下个字符
            for(char c : to_string(j - i))          //统计s[i]出现的次数，10次要分成'1','0'加入
                s[index++] = c;
        }
        return index;
    }
};