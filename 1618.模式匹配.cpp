class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int anums = 0, bnums = 0;
        int lengthv = value.size();
        if (pattern.size() == 0 && lengthv == 0) return true;
        else if (pattern.size() == 0) return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'a') anums++;
            else bnums++;
        }
        int maxa = 0, maxb = 0;
        if (anums != 0) maxa = lengthv / anums;
        if (bnums != 0) maxb = lengthv / bnums;
        for (int i = 0; i <= maxa; ++i) {
            for (int j = 0; j <= maxb; ++j) {
                if (i * anums + j * bnums == lengthv) {
                    string stra = "!";
                    string strb = "!";
                    int index = 0;
                    for (int x = 0; x < pattern.size(); x++) {
                        if (pattern[x] == 'a') {
                            if (stra == "!") stra = value.substr(index, i);
                            else if (stra != value.substr(index, i)) break;
                            index += i;
                        }
                        else {
                            if (strb == "!")  strb = value.substr(index, j);
                            else if (strb != value.substr(index, j)) break;
                            index += j;
                        }
                    }
                    if (index == lengthv&&stra!=strb) return true;
                }
            }
        }
        return false;
    }
};