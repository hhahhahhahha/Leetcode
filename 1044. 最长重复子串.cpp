class Solution {
public:
     string longestDupSubstring(string S) {
        string ans;
        pretreat(S);
        ans = binary_serach(S, 0, S.length());
        return ans;
    }
    Solution()
    {
        #define MAXN int(1e5+5)
        #define MOD 200003
        #define IDF 132453
    }

private:
    const int base = 127;
    unsigned long long int hash_table[MAXN];
    unsigned long long int table[MAXN];
    void pretreat(string obj)
    {
        table[0] = 1;
        unsigned long long int value = 0;
        int len = obj.length();
        for (int i = 0; i < len; i++)
        {
            table[i+1] = table[i] * base;
            value *= base;
            value += obj[i];
            hash_table[i] = value;
        }
    }

    inline unsigned long long int find_hash_value(int l, int r) const
    {
        if (l == 0) return hash_table[r];
        return hash_table[r] - hash_table[l-1] * table[r-l+1];
    }

    unsigned long long int h[MOD];
    string ans = "";
    inline int my_hash(unsigned long long int v) {return v % MOD;}
    bool push(unsigned long long int v)
    {
        int tmp = my_hash(v);
        while (h[tmp] != IDF && h[tmp] != v)
        {
            tmp++;
            if (tmp >= MOD) tmp -= MOD;
        }
        if (h[tmp] == IDF)  {h[tmp] = v; return true;}
        else return false;
        
    }

    bool check(string s, int value)
    {
        int len = s.length() - value + 1;
        for (int i = 0; i < len; i++)
        {
            if (!push(find_hash_value(i, i + value - 1))) 
            {
                ans = s.substr(i, value);
                return true; 
            }
        }
        return false;
    }

    string binary_serach(string s, int l, int r)
    {
        int mid = (l+r+1)/2;
        while (l < r)
        {
            for (int i = 0; i < MOD; i++)
            {
                h[i] = IDF;
            }
            mid = (l+r+1)/2;
            if (check(s, mid)) l = mid;
            else r = mid - 1;
        }
        return ans;
    }
};