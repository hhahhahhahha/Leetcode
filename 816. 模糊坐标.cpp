class Solution {
public:
    vector<string> ambiguousCoordinates(string T) {
        vector<string> res;
        if (T.empty()) {
            return res;
        }

        auto S = T.substr(1, T.size() - 2);
        cout << S << endl;
        int N = S.size();
        for (int i = 1; i < N; i++) {
            auto x = S.substr(0, i);
            auto y = S.substr(i);
            cout << x << " : " << y << endl;
            auto vx = getValidSplits(x);
            auto vy = getValidSplits(y);
            for (const auto& c1 : vx) {
                for (const auto& c2 : vy) {
                    res.push_back("(" + c1 + ", " + c2 + ")");
                }
            }
        }

        return res;
    }

private:
    bool isValidInteger(string str) {
        return str.size() == 1 || str[0] != '0';
    }

    bool isValidDecimal(string str) {
        return str.back() != '0';
    }

    vector<string> getValidSplits(string str) {
        vector<string> res;
        if (isValidInteger(str)) {
            res.push_back(str); // don't add . at all
        }

        for (int i = 1; i < str.size(); i++) {
            auto integer = str.substr(0, i); // prefix zeros have checked before
            auto decimal = str.substr(i);
            if (isValidInteger(integer) && isValidDecimal(decimal)) {
                res.push_back(integer + "." + decimal);
            }
        }

        return res; 
    }
};